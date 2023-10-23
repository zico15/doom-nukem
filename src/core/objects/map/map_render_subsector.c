#include "Map.h"

static t_vertex *get_vertex(t_map *this, int vertex_id)
{
    return array(this->vertexes)->get(vertex_id);
}

void __render_subsector(t_map *this, SDL_Renderer *renderer, int subsector_id)
{
    t_wad_subsector *subsector = array(this->subsectors)->get(subsector_id);

    SDL_SetRenderDrawColor(renderer, rand() % 255, rand() % 255, rand() % 255, SDL_ALPHA_OPAQUE);

    for (int i = 0; i < subsector->seg_count; i++)
    {
        t_wad_seg *seg = array(this->segs)->get(subsector->first_seg_id + i);
        t_vertex *vStart = get_vertex(this, seg->start_vertex_id);
        t_vertex *vEnd = get_vertex(this, seg->end_vertex_id);
        if (!clip_vertexes_in_fov(this, vStart, vEnd))
            continue;
        SDL_RenderDrawLine(renderer,
                           remap_x_screen(this, get_vertex(this, seg->start_vertex_id)->x_position),
                           remap_y_screen(this, get_vertex(this, seg->start_vertex_id)->y_position, renderer),
                           remap_x_screen(this, get_vertex(this, seg->end_vertex_id)->x_position),
                           remap_y_screen(this, get_vertex(this, seg->end_vertex_id)->y_position, renderer));
    }
}

void rotate_left(t_map *this)
{
    this->player.angle += (0.1875f * 5);
    this->player.angle = normalize_angle(this->player.angle);
    printf("angle:%f\n", this->player.angle);
}

void rotate_right(t_map *this)
{
    this->player.angle -= (0.1875f * 5);
    this->player.angle = normalize_angle(this->player.angle);
    printf("angle:%f\n", this->player.angle);
}