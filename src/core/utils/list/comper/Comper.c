#include "ArrayList.h"

static int cmp_void(void *a, void *b)
{
    return (a == b);
}

static int cmp_int(void *a, void *b)
{
    return (*(int *)a == *(int *)b);
}

// static int cmp_str(void *a, void *b)
// {
//     return (string().equals((char *)a, (char *)b));
// }

t_cmp get_cmp(t_type_node type)
{
    if (type == VOID)
        return (cmp_void);
    if (type == INT)
        return (cmp_int);
    if (type == STR)
        return ((t_cmp)string().equals);
    return (NULL);
}