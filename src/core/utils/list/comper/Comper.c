#include "ArrayList.h"

static int cmp_void(void *a, void *b)
{
    return (a == b);
}

static int cmp_int(void *a, void *b)
{
    return (*(int *)a == *(int *)b);
}
t_cmp get_cmp(t_type_node type)
{
    if (type == OBJECT)
        return (cmp_void);
    if (type == INT)
        return (cmp_int);
    if (type == STR)
        return ((t_cmp)string().equals);
    return (NULL);
}