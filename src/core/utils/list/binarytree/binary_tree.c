
#include "ArrayList.h"

static t_node *__add(void *value)
{
    t_node *node;
    struct s_binary_tree_private *b;

    b = *this();
    if (!b || !value)
        return (NULL);
    node = ft_calloc(sizeof(t_node));
    if (!node)
        return (NULL);
    node->value = value;
    node->destroy = &free;
    if (b->size == 0)
    {
        b->root = node;
        b->size++;
        printf("roor\n");
        return (node);
    }
    printf("add\n");
    return (node);
}

void *new_binary_tree(t_type_node type)
{
    t_binary_tree *b;

    b = extender_array(type, sizeof(struct s_binary_tree_private));
    if (!b)
        return (NULL);
    b->add = __add;
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