#ifndef VIEW_RENDERER_H
#define VIEW_RENDERER_H

#include "Engine.h"

typedef struct s_view_renderer t_view_renderer;

struct s_view_renderer
{
    int render_x_size;
    int render_y_size;
    int auto_map_scale_factor;

    t_map *map;
    t_player *player;

    SDL_Renderer *m_pRenderer;
};

//functions:
void init(t_map *map, t_player *player);
void render(bool is_automap);
void add_wall_in_fov(t_wad_seg *seg, float V1Angle, float V2Angle, SDL_Renderer *renderer);
void init_frame();
void set_draw_color(int r, int g, int b);
void draw_rect(int x1, int y1, int x2, int y2);
void draw_line(int x1, int y1, int x2, int y2);

void render_auto_map();
void render_3d_view();

int angle_to_screen(float angle);
int remap_x_screen(t_map *map, int x_map_position);//ok
int remap_y_screen(t_map *map, int y_map_position, SDL_Renderer *renderer);//ok

#endif