#include "Map.h"

void __render_map_wall(t_map *this, SDL_Renderer *renderer, int iXShift, int iYShift)
{
    t_node *linedefs;
    t_node *vertexes;
    size_t size;
    size_t i;
    int i_render_x;
    int i_render_y = 200;

    SDL_RenderGetLogicalSize(renderer, &i_render_x, &i_render_y);
    --i_render_y;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    linedefs = array(this->linedefs)->array;
    vertexes = array(this->vertexes)->array;
    i = 0;
    size = array(this->linedefs)->size;
    while (i < size)
    {
        t_vertex *vStart = (t_vertex *)vertexes[((t_linedef *)linedefs[i].value)->start_vertex].value; // Read the first point
        t_vertex *vEnd = (t_vertex *)vertexes[((t_linedef *)linedefs[i].value)->end_vertex].value;     // Read the second point
        SDL_RenderDrawLine(renderer,
                           (vStart->x_position + iXShift) / this->scale,
                           i_render_y - (vStart->y_position + iYShift) / this->scale,
                           (vEnd->x_position + iXShift) / this->scale,
                           i_render_y - (vEnd->y_position + iYShift) / this->scale);
        i++;
    }
}

void __render_map_wall_player(t_map *this, SDL_Renderer *renderer, int iXShift, int iYShift)
{
    int iRenderXSize;
    int iRenderYSize;

    SDL_RenderGetLogicalSize(renderer, &iRenderXSize, &iRenderYSize);
    --iRenderXSize;
    --iRenderYSize;
    // Let's draw player in Red
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    printf("__render_map_wall_player:%d / %d\n", (this->player.x_position + iXShift) / this->scale, (iRenderYSize - (this->player.y_position + iYShift) / this->scale));
    for (int i = 0; i < 9; ++i)
    {
        SDL_RenderDrawPoint(renderer,
                            (this->player.x_position + iXShift) / this->scale + this->direction[i][0],
                            (iRenderYSize - (this->player.y_position + iYShift) / this->scale + this->direction[i][1]));
    }
}