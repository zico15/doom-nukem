#include <WADData.h>

static void init(char *wad_path)
{
    WADData()->wad_file = fopen(wad_path, "rb");
    if (WADData()->wad_file == NULL)
    {
        fprintf(stderr, "Value of errno: %d\n", errno);
        perror("Error printed by DoomEngine init instance");
        printf("Error opening file: %s\n", wad_path);
    }
    WADData()->header = malloc(sizeof(WADHeader));
    WADData()->read_header();
    printf("WAD Type: %s\n", WADData()->header->wad_type);
    printf("Lump Count: %d\n", WADData()->header->lump_count);
    printf("Init Offset: %d\n", WADData()->header->init_offset);
}

static void close(void)
{
    fclose(WADData()->wad_file);
}

// Function to read a specified number of bytes from a file
static int read_bytes(FILE* file, long offset, size_t num_bytes, void* buffer) {
    if (fseek(file, offset, SEEK_SET) != 0) {
        // Error handling: Unable to set the file pointer to the specified offset
        return -1;
    }
    
    size_t read_size = fread(buffer, 1, num_bytes, file);
    
    if (read_size != num_bytes) {
        // Error handling: Unable to read the specified number of bytes
        return -1;
    }
    
    return 0; // Success
}

// Function to read and interpret a single byte
static uint8_t read_1_byte(FILE* file, long offset) {
    uint8_t value;
    if (read_bytes(file, offset, 1, &value) == 0) {
        return value;
    }
    // Error handling: Unable to read the byte
    return 0;
}

// Function to read and interpret a 2-byte integer
static int16_t read_2_bytes(FILE* file, long offset) {
    int16_t value;
    if (read_bytes(file, offset, 2, &value) == 0) {
        return value;
    }
    // Error handling: Unable to read the 2 bytes
    return 0;
}

// Function to read and interpret a 4-byte integer
static int32_t read_4_bytes(FILE* file, long offset) {
    int32_t value;
    if (read_bytes(file, offset, 4, &value) == 0) {
        return value;
    }
    // Error handling: Unable to read the 4 bytes
    return 0;
}

// Function to read and interpret a string
static char* read_string(FILE* file, long offset, size_t num_bytes) {
    char *result = (char*)malloc(num_bytes + 1);
    if (result == NULL) {
        // Error handling: Unable to allocate memory
        return NULL;
    }
    
    if (read_bytes(file, offset, num_bytes, result) == 0) {
        result[num_bytes] = '\0';

        // Handle string termination (e.g., remove null characters)
        for (size_t i = 0; i < num_bytes; i++) {
            if (result[i] == '\0') {
                result[i] = ' ';
            }
        }
        return result;
    } else {
        // Error handling: Unable to set the file pointer or read the string
        free(result);
        return NULL;
    }
}

//It will read the header information and populate the WADHeader structure
static void read_header() {
    if (WADData()->header == NULL) {
        // Handle an invalid argument
        return;
    }

    if (read_bytes(WADData()->wad_file, 0, 4, WADData()->header->wad_type) != 0) {
        // Error handling: Unable to read the WAD type string
        return;
    }

    WADData()->header->lump_count = read_4_bytes(WADData()->wad_file, 4);
    WADData()->header->init_offset = read_4_bytes(WADData()->wad_file, 8);
}

t_WADData *WADData()
{
    static t_WADData e = {
        NULL,
        NULL,
        init,
        close,
        read_bytes,
        read_1_byte,
        read_2_bytes,
        read_4_bytes,
        read_string,
        read_header,
    };

    return (&e);
}