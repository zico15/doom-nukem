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

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include "ft_util.h"

typedef struct s_node t_node;
typedef struct s_array t_array;
typedef int (*t_cmp)(void *a, void *b);

typedef enum e_type_node
{
	VOID,
	INT,
	STR
} t_type_node;

struct s_node
{
	int index;
	void (*destroy)(t_node *e);
	t_node *next;
	t_node *prev;
	char *key;
	void *value;
};

struct s_array
{
	t_node *begin;
	t_node *end;
	int size;
	int is_value_destroy;
	t_node *(*add)(t_array *a, void *value);
	t_node *(*remove)(t_array *a, void *value);
	void *(*get)(t_array *a, int index);
	t_node *(*set)(int index, void *value);
	void (*remove_index)(int index);
	int (*destroy)();
	void (*destroy_element)(t_node *e);
	void (*for_each)(void (*fun)(t_node *e, void *v), void *o);
	void **(*to_array)(void);
	void (*remove_value)(void *value);
	void (*remove_all)(void);
	int (*cmp)(void *a, void *b);
	t_node *next;
};

typedef struct s_hashmap
{
	t_array *list;
	int (*size)(void);
	t_node *(*put)(char *key, void *value);
	t_node *(*get_index)(int index);
	t_node *(*get_key)(char *key);
	void (*remove_index)(int index);
	void (*remove_key)(char *key);
	int (*destroy)();
	void (*for_each)(void (*fun)(t_node *e, void *v), void *o);
	void **(*to_str)(void);
} t_hashmap;

void *new_array(t_type_node type);
t_cmp get_cmp(t_type_node type);

// t_array *array(t_array *this);
// void *new_hashmap(void);
// t_hashmap *hashmap(t_hashmap *this);

#endif
