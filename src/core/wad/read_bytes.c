#include <WADData.h>

// Function to read and interpret a single byte
uint8_t read_1_byte(const uint8_t *data, long offset)
{
    uint8_t value;

    memcpy(&value, data + offset, sizeof(uint8_t));
    return (value);
}

// Function to read and interpret a 2-byte integer
int16_t read_2_bytes(const uint8_t *data, long offset)
{
    int16_t value;

    memcpy(&value, data + offset, sizeof(int16_t));
    return (value);
}

// Function to read and interpret a 4-byte integer
int32_t read_4_bytes(const uint8_t *data, long offset)
{
    int32_t value;

    memcpy(&value, data + offset, sizeof(int32_t));
    return value;
}

void read_header(const uint8_t *data, long offset, t_wad_header *header)
{
    header->identification[0] = read_1_byte(data, offset);
    header->identification[1] = read_1_byte(data, offset + 1);
    header->identification[2] = read_1_byte(data, offset + 2);
    header->identification[3] = read_1_byte(data, offset + 3);
    header->identification[3] = '\0';
    header->numLumps = read_4_bytes(data, offset + 4);
    header->directoryOffset = read_4_bytes(data, offset + 8);
}