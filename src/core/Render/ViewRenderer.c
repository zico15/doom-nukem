#include <ViewRenderer.h>

void add_wall_in_fov(t_wad_seg *seg, float V1Angle, float V2Angle, SDL_Renderer *renderer)
{
    int V1XScreen = angle_to_screen(V1Angle);
    int V2XScreen = angle_to_screen(V2Angle);

    SDL_RenderDrawLine(renderer, V1XScreen, 0, V1XScreen, 300);
    SDL_RenderDrawLine(renderer, V2XScreen, 0, V2XScreen, 300);
}

int remap_x_screen(t_map *map, int x_map_position)
{
    return (x_map_position + (-map->min_x)) / map->scale;
}

int remap_y_screen(t_map *map, int y_map_position, SDL_Renderer *renderer)
{
    int i_render_x;
    int i_render_y;

    SDL_RenderGetLogicalSize(renderer, &i_render_x, &i_render_y);
    --i_render_y;
    return (i_render_y - (y_map_position + (-map->min_y)) / map->scale);
}


int angle_to_screen(float angle)
{
    int iX = 0;

    // Left side
    if (angle > 90)
    {
        angle -= 90;
        angle = normalize_angle(angle);
        iX = 160 - round(tanf(angle * PI / 180.0f) * 160);
    }
    else
    {
        // Right side
        angle = 90 - angle;
        angle = normalize_angle(angle);
        iX = round(tanf(angle * PI / 180.0f) * 160);
        iX += 160;
    }

    return iX;
}