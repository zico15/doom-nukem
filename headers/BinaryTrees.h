/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:09:04 by edos-san          #+#    #+#             */
/*   Updated: 2022/02/19 18:09:04 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include "ft_util.h"
#include <stdbool.h>

typedef struct s_bnode t_bnode;
typedef struct s_binary_tree t_binary_tree;

struct s_bnode
{
	long long id;
	void *value;
	void (*destroy)(void *value);
	t_bnode *left;
	t_bnode *right;
};

struct s_binary_tree
{
	size_t size;
	int is_value_destroy;
	t_bnode *(*insert)(int id, void *value);
	void (*remove)(void *value, bool is_free_value);
	t_bnode *(*search)(int id);
	t_bnode *(*set)(int index, void *value);
	void (*remove_index)(int index);
	void (*destroy)();
	void (*destroy_element)(t_bnode *e);
	void (*for_each)(void (*fun)(t_bnode *e, void *v), void *o);
	void **(*to_array)(void);
	void (*remove_value)(void *value);
	void (*remove_all)(void);
	void (*test)();
	int (*cmp)(void *a, void *b);
	t_bnode *root;
};

struct s_binary_tree_private
{
	size_t size;
	int is_value_destroy;
	t_bnode *(*insert)(int id, void *value);
	void (*remove)(void *value, bool is_free_value);
	void *(*search)(int id);
	t_bnode *(*set)(int index, void *value);
	void (*remove_index)(int index);
	void (*destroy)();
	void (*destroy_element)(t_bnode *e);
	void (*for_each)(void (*fun)(t_bnode *e, void *v), void *o);
	void **(*to_array)(void);
	void (*remove_value)(void *value);
	void (*remove_all)(void);
	void (*test)();
	int (*cmp)(void *a, void *b);
	t_bnode *root;
	t_bnode *ret;
};

void *new_binary_tree(t_type_node type);
void printf_tree(t_bnode *node, int level);
t_binary_tree *binary(t_binary_tree *tree);

#endif
