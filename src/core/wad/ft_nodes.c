#include "Engine.h"

static t_wad_node *read_node_data(const uint8_t *pWADData, int offset, t_map *map)
{
    t_wad_node *node;

    node = ft_calloc(sizeof(t_wad_node));
    node->x_partition = read_2_bytes(pWADData, offset);     // - map->min_x;
    node->y_partition = read_2_bytes(pWADData, offset + 2); // - map->min_y;
    node->change_x_partition = read_2_bytes(pWADData, offset + 4);
    node->change_y_partition = read_2_bytes(pWADData, offset + 6);

    node->right_box_top = read_2_bytes(pWADData, offset + 8);     // - map->min_y;
    node->right_box_bottom = read_2_bytes(pWADData, offset + 10); // - map->min_y;
    node->right_box_left = read_2_bytes(pWADData, offset + 12);   // - map->min_x;
    node->right_box_right = read_2_bytes(pWADData, offset + 14);  // - map->min_x;

    node->left_box_top = read_2_bytes(pWADData, offset + 16);    // - map->min_y;
    node->left_box_bottom = read_2_bytes(pWADData, offset + 18); // - map->min_y;
    node->left_box_left = read_2_bytes(pWADData, offset + 20);   // - map->min_x;
    node->left_box_right = read_2_bytes(pWADData, offset + 22);  // - map->min_x;

    node->right_child_id = read_2_bytes(pWADData, offset + 24);
    node->left_child_id = read_2_bytes(pWADData, offset + 26);
    return (node);
}
void read_map_nodes(t_wadd_data *wad_data, t_map *map)
{
    int i;
    int index;
    int count_nodes;
    t_wad_node *node;

    printf("read_map_node\n");
    index = map->map_index + NODES;
    if (index == NODES || !string().equals_n(wad_data->directory[index].name, "NODES", 5))
    {
        printf("Map %s not found\n", map->name);
        return;
    }
    printf("NODES: %s\n", wad_data->directory[index].name);
    count_nodes = wad_data->directory[index].size / sizeof(t_wad_node);
    i = 0;
    while (i < count_nodes)
    {
        node = (t_wad_node *)array(map->nodes)->add(read_node_data(wad_data->data, wad_data->directory[index].offset + i * sizeof(t_wad_node), map))->value;
        i++;
        printf("XPartition: %i, YPartition: %i, ChangeXPartition: %i, ChangeYPartition: %i, RightBoxTop: %i, RightBoxBottom: %i, RightBoxLeft: %i, RightBoxRight: %i, LeftBoxTop: %i, LeftBoxBottom: %i, LeftBoxLeft: %i, LeftBoxRight: %i, RightChildID: %i, LeftChildID: %i\n", node->x_partition, node->y_partition, node->change_x_partition, node->change_y_partition, node->right_box_top, node->right_box_bottom, node->right_box_left, node->right_box_right, node->left_box_top, node->left_box_bottom, node->left_box_left, node->left_box_right, node->right_child_id, node->left_child_id);
    }
}