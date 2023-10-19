
#include "BinaryTrees.h"

t_bnode *__binary_tree_search(int id);
t_bnode *__binary_tree_insert(int id, void *value);

t_binary_tree *binary(t_binary_tree *array)
{
    (*this()) = array;
    return (array);
}

void *new_binary_tree(t_type_node type)
{
    t_binary_tree *b;

    b = extender_array(type, sizeof(struct s_binary_tree_private));
    if (!b)
        return (NULL);
    b->insert = __binary_tree_insert;
    b->search = __binary_tree_search;
    // a->get = __get;
    // a->set = __set_array;
    // a->remove = __remove;
    // a->cmp = get_cmp(type);
    // a->for_each = __for_each;
    // a->test = test;
    // a->destroy = __destroy_array;
    // array(a);
    return (b);
}