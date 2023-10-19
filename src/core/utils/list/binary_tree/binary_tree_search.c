
#include "BinaryTrees.h"

static void __search_node(struct s_binary_tree_private *b, t_bnode *node, int id)
{
    if (!node)
        return;
    if (node->id == id)
        b->ret = node;
    if (!node->right && !node->left)
    {
        printf("node: %llu\n", node->id);
    }
    if (node->id < id)
    {
        __search_node(b, node->right, id);
        __search_node(b, node->left, id);
    }
    else
    {
        __search_node(b, node->left, id);
        __search_node(b, node->right, id);
    }
}

t_bnode *__binary_tree_search(int id)
{
    struct s_binary_tree_private *b;

    b = *this();
    if (!b)
        return (NULL);
    b->ret = NULL;
    __search_node(b, b->root, id);
    return (b->ret);
}