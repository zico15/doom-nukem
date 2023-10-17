#ifndef WADDATA_H
#define WADDATA_H
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

enum e_EMAPLUMPSINDEX
{
    THINGS = 1,
    LINEDEFS,
    SIDEDDEFS,
    VERTEXES,
    SEAGS,
    SSECTORS,
    NODES,
    SECTORS,
    REJECT,
    BLOCKMAP,
    COUNT
};

enum e_ELINEDEFFLAGS
{
    BLOCKING = 0,
    BLOCKMONSTERS = 1,
    TWOSIDED = 2,
    DONTPEGTOP = 4,
    DONTPEGBOTTOM = 8,
    SECRET = 16,
    SOUNDBLOCK = 32,
    DONTDRAW = 64,
    DRAW = 128
};

typedef struct s_wadd_data t_wadd_data;
typedef struct s_wad_header t_wad_header;
typedef struct s_map t_map;
typedef struct s_wadd_thing t_wadd_thing;
typedef struct s_wad_directory t_wad_directory;
typedef struct s_wad_node t_wad_node;
typedef struct s_wad_subsector t_wad_subsector;
typedef struct s_wad_seg t_wad_seg;

typedef struct s_vertex
{
    int16_t x_position;
    int16_t y_position;
} t_vertex;

typedef struct s_linedef
{
    uint16_t start_vertex;
    uint16_t end_vertex;
    uint16_t flags;
    uint16_t line_type;
    uint16_t sector_tag;
    uint16_t right_sidedef;
    uint16_t left_sidedef;
} t_linedef;

struct s_wad_directory
{
    uint32_t offset;
    uint32_t size;
    char name[8];
};

struct s_wad_header
{
    char identification[4];
    uint32_t numLumps;
    uint32_t directoryOffset;
};

// Estrutura de diretório de um lump WAD

struct s_wadd_data
{
    FILE *file;
    t_wad_header header;
    uint8_t *data;
    t_wad_directory *directory;
    void *things;
    bool is_valid;
};

struct s_wadd_thing
{
    int16_t x_position;
    int16_t y_position;
    uint16_t angle;
    uint16_t type;
    uint16_t flags;
};

struct s_wad_node
{
    int16_t x_partition;
    int16_t y_partition;
    int16_t change_x_partition;
    int16_t change_y_partition;

    int16_t right_box_top;
    int16_t right_box_bottom;
    int16_t right_box_left;
    int16_t right_box_right;

    int16_t left_box_top;
    int16_t left_box_bottom;
    int16_t left_box_left;
    int16_t left_box_right;

    uint16_t right_child_id;
    uint16_t left_child_id;
};

struct s_wad_subsector
{
    uint16_t seg_count;
    uint16_t first_seg_id;
};

struct s_wad_seg
{
    uint16_t StartVertexID;
    uint16_t EndVertexID;
    uint16_t Angle;
    uint16_t LinedefID;
    uint16_t Direction; // 0 same as linedef, 1 opposite of linedef
    uint16_t Offset;    // distance along linedef to start of seg
};

t_wadd_data init_wad_data(char *wad_path);
uint8_t read_1_byte(const uint8_t *data, long offset);
int16_t read_2_bytes(const uint8_t *data, long offset);
int32_t read_4_bytes(const uint8_t *data, long offset);
int find_map_index(t_wadd_data *wad_data, char *map_name);
void normalize_vertex(t_map *map);
void read_map_vertex(t_wadd_data *wad_data, t_map *map);
void read_header(const uint8_t *data, long offset, t_wad_header *header);
void read_map_things(t_wadd_data *wad_data, t_map *map);
void read_map_linedef(t_wadd_data *wad_data, t_map *map);
void read_map_nodes(t_wadd_data *wad_data, t_map *map);
void read_map_subsectors(t_wadd_data *wad_data, t_map *map);

#endif