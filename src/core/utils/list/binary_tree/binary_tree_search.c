
#include "BinaryTrees.h"

static t_bnode *__search_node(t_bnode *node, int id)
{
    // Is this a valid node?
    if (!node)
        return (NULL);

    // Is this what I'm looking for?
    if (node->id == id && printf("node: %p\n", node))
        return (node);

    // I didn't find what I'm looking for :(, where should I look?
    if (node->id < id)
        return (__search_node(node->right, id));
    else
        return (__search_node(node->left, id));
}

t_bnode *__binary_tree_search(int id)
{
    struct s_binary_tree_private *b;

    b = *this();
    if (!b)
        return (NULL);
    return (__search_node(b->root, id));
}