
#include "BinaryTrees.h"

int deep_node(t_bnode *node, int level)
{
    if (node == NULL)
        return (level);
    int left = deep_node(node->left, level + 1);
    int right = deep_node(node->right, level + 1);
    return (left > right ? left : right);
}

void __printf_tree(t_bnode *root, int level)
{
    if (root == NULL)
    {
        return;
    }

    int i;
    // Espaçamento para criar recuo
    for (i = 0; i < level; i++)
        printf(" ");
    printf("%lld", root->id);

    // Chamada recursiva para a subárvore direita com nível aumentado
    for (i = 0; i < level; i++)
        printf(" ");
    __printf_tree(root->right, level - 1);

    // Chamada recursiva para a subárvore esquerda com nível aumentado
    __printf_tree(root->left, level - 1);
    printf("\n");
}

void printf_tree(t_bnode *root, int level)
{
    printf("================================\n"
           "level: %d\n",
           deep_node(root, 0));
    __printf_tree(root, deep_node(root, 0));
}

t_bnode *new_bnode(long long id, void *value)
{
    t_bnode *node;

    node = ft_calloc(sizeof(t_bnode));
    if (!node)
        return (NULL);
    node->id = id;
    node->value = value;
    node->destroy = free;
    return (node);
}

static void __insert(t_bnode *root, t_bnode *node)
{
    if (node->id < root->id)
    {
        if (root->left == NULL)
        {
            printf("node_left: %lld\n", node->id);
            root->left = node;
        }
        else
            __insert(root->left, node);
    }
    else
    {
        if (root->right == NULL)
        {
            printf("node_right: %lld\n", node->id);
            root->right = node;
        }
        else
            __insert(root->right, node);
    }
}

t_bnode *__binary_tree_insert(int id, void *value)
{
    struct s_binary_tree_private *b;
    t_bnode *node;

    b = *this();
    if (!b)
        return (NULL);
    node = new_bnode(id, value);
    if (b->root == NULL)
    {
        b->root = node;
        return (node);
    }
    __insert(b->root, node);
    return (node);
}