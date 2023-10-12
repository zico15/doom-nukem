#ifndef WADDATA_H
#define WADDATA_H
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <stdint.h>
 
typedef struct s_WADData t_WADData;

typedef struct {
    char wad_type[5];  // A 4-character WAD type string
    int32_t lump_count; // Number of lumps
    int32_t init_offset; // Offset to the start of data
} WADHeader;

struct s_WADData
{
    FILE *wad_file;
    WADHeader *header;

    //Functions
    void (*init)(char *wad_path);
    void (*close)();
    int (*read_bytes)(FILE* file, long offset, size_t num_bytes, void* buffer);
    uint8_t (*read_1_byte)(FILE* file, long offset);
    int16_t (*read_2_bytes)(FILE* file, long offset);
    int32_t (*read_4_bytes)(FILE* file, long offset);
    char* (*read_string)(FILE* file, long offset, size_t num_bytes);
    void (*read_header)();
};

t_WADData *WADData();

#endif