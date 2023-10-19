
#include "BinaryTrees.h"

t_bnode *__binary_tree_search(int id);
t_bnode *__binary_tree_insert(int id, void *value);

t_binary_tree *binary(t_binary_tree *array)
{
    (*this()) = array;
    return (array);
}

static void __destroy_node(t_bnode *node)
{
    if (!node)
        return;
    __destroy_node(node->left);
    __destroy_node(node->right);
    if (node->destroy)
        node->destroy(node->value);
    free(node);
}

static void __destroy_tree()
{
    struct s_binary_tree_private *b;

    b = *this();
    if (!b)
        return;
    __destroy_node(b->root);
    free(b);
}

void *new_binary_tree(t_type_node type)
{
    t_binary_tree *b;

    b = ft_calloc(sizeof(struct s_binary_tree_private));
    if (!b)
        return (NULL);
    b->insert = __binary_tree_insert;
    b->search = __binary_tree_search;
    b->destroy = __destroy_tree;
    // a->get = __get;
    // a->set = __set_array;
    // a->remove = __remove;
    // a->cmp = get_cmp(type);
    // a->for_each = __for_each;
    // a->test = test;
    return (b);
}