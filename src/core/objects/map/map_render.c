#include "Map.h"
#define SUBSECTORIDENTIFIER 0x8000

int RemapXToScreen(t_map *map, int XMapPosition)
{
    return (XMapPosition + (-map->min_x)) / map->scale;
}

int RemapYToScreen(t_map *map, int YMapPosition, SDL_Renderer *renderer)
{
    int i_render_x;
    int i_render_y;

    SDL_RenderGetLogicalSize(renderer, &i_render_x, &i_render_y);
    --i_render_y;
    return (i_render_y - (YMapPosition + (-map->min_y)) / map->scale);
}


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
                           RemapXToScreen(this, vStart->x_position),
                           RemapYToScreen(this, vStart->y_position, renderer),
                           RemapXToScreen(this, vEnd->x_position),
                           RemapYToScreen(this, vEnd->y_position, renderer));
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
                            RemapXToScreen(this, this->player.x_position) + this->direction[i][0],
                            (RemapYToScreen(this, this->player.y_position, renderer) + this->direction[i][1]));
    }
}

void __render_auto_map_node(t_map *this, SDL_Renderer *renderer, int iXShift, int iYShift)
{
    t_wad_node *node = array(this->nodes)->get((array(this->nodes)->size - 1));

    SDL_Rect RightRect = {
        RemapXToScreen(this, node->right_box_left),
        RemapYToScreen(this, node->right_box_top, renderer),
        RemapXToScreen(this, node->right_box_right) - RemapXToScreen(this, node->right_box_left) + 1,
        RemapYToScreen(this, node->right_box_bottom, renderer)- RemapYToScreen(this, node->right_box_top, renderer) + 1
    };

    SDL_Rect LeftRect = {
        RemapXToScreen(this, node->left_box_left),
        RemapYToScreen(this, node->left_box_top, renderer),
        RemapXToScreen(this, node->left_box_right) - RemapXToScreen(this, node->left_box_left) + 1,
        RemapYToScreen(this, node->left_box_bottom, renderer) - RemapYToScreen(this, node->left_box_top, renderer) + 1
    };

    printf("A posiçao do rectangulo: %i\n", RemapYToScreen(this, node->left_box_top, renderer));
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE); 
    SDL_RenderDrawRect(renderer, &RightRect);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(renderer, &LeftRect);

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer,
        RemapXToScreen(this, node->x_partition),
        RemapYToScreen(this, node->y_partition, renderer),
        RemapXToScreen(this, node->x_partition + node->change_x_partition),
        RemapYToScreen(this, node->y_partition + node->Change_y_partition, renderer));
}

bool IsPointOnLeftSide(t_map *map, int XPosition, int YPosition, int iNodeID)
{
    //int dx = XPosition - m_Nodes[iNodeID].XPartition; // Find X the point relative to the player 
    int dx = XPosition - ((t_wad_node *)array(map->nodes)->get(iNodeID))->x_partition; // Find X the point relative to the player 
    int dy = YPosition - ((t_wad_node *)array(map->nodes)->get(iNodeID))->y_partition; // Find y the point relative to the player 

    return (((dx * ((t_wad_node *)array(map->nodes)->get(iNodeID))->Change_y_partition) - (dy * ((t_wad_node *)array(map->nodes)->get(iNodeID))->change_x_partition)) <= 0);
}

void RenderSubsector(int iSubsectorID)
{
    // for now, just let us keep this empty
}

void RenderBSPNodes(int iNodeID)
{
    // Masking all the bits except the last one
    // to check if this is a subsector
    // if (iNodeID & SUBSECTORIDENTIFIER)
    // {
    //     RenderSubsector(iNodeID & (~SUBSECTORIDENTIFIER));
    //     return;
    // }

    // bool isOnLeft = IsPointOnLeftSide(m_pPlayer->GetXPosition(), m_pPlayer->GetYPosition(), iNodeID);

    // if (isOnLeft)
    // {
    //     RenderBSPNodes(m_Nodes[iNodeID].LeftChildID);
    // }
    // else
    // {
    //     RenderBSPNodes(m_Nodes[iNodeID].RightChildID);
    // }
}

void __renderBSPNodes(t_map *map)
{
    RenderBSPNodes(array(map->nodes)->size - 1);
}
