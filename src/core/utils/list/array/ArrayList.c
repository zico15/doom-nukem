/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:51:06 by edos-san          #+#    #+#             */
/*   Updated: 2022/02/20 13:51:06 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ArrayList.h"

static void *get(int index)
{
	t_array *a;

	a = *this();
	if (!a || index < 0 || index >= a->size)
		return (NULL);
	return (a->array[index]->value);
}

static void __for_each(void (*fun)(t_node *node, void *v), void *o)
{
	size_t i;
	t_array *a;

	a = *this();
	if (!a || !fun)
		return;
	i = -1;
	while (a->array[++i])
		fun(a->array[i], o);
}

static t_node *__add(void *value)
{
	t_node *e;
	t_array *a;

	a = *this();
	if (!a || !value)
		return (NULL);
	e = ft_calloc(sizeof(t_node));
	if (!e)
		return (NULL);
	e->value = value;
	e->index = a->size;
	a->size++;
	if (a->size >= a->vsize)
	{
		a->vsize += 10;
		a->array = ft_realloc(a->array, a->vsize * sizeof(t_node *));
	}
	a->array[e->index] = e;
	return (e);
}

static void __remove(void *value)
{
	size_t i;
	bool is_realloc;
	t_array *a;

	a = *this();
	if (!a || !value)
		return;
	i = -1;
	is_realloc = false;
	while (a->array[++i])
	{
		if (is_realloc)
		{
			a->array[i - 1] = a->array[i];
			a->array[i - 1]->index = i - 1;
			a->array[i] = NULL;
		}
		else if (a->cmp(a->array[i]->value, value))
		{
			is_realloc = true;
			if (a->array[i]->destroy)
				a->array[i]->destroy(a->array[i]);
			a->array[i] = NULL;
		}
	}
}

void *new_array(t_type_node type)
{
	t_array *a;

	a = ft_calloc(sizeof(t_array));
	if (!a)
		return (NULL);
	a->add = __add;
	a->remove = __remove;
	a->cmp = get_cmp(type);
	a->for_each = __for_each;
	// a->size = 0;
	// a->begin = NULL;
	// a->end = NULL;
	// a->add = base_add_element;
	// a->get = base_get_element;
	// a->remove = base_remove_element;
	// a->destroy = base_destroy;
	// a->for_each = __base_for_each;
	// a->set = __base_set_element;
	// a->remove_index = __base_remove_element_index;
	// a->to_str = __to_str;
	// a->destroy_element = __destroy_element;
	// a->is_value_destroy = 1;
	// a->remove_value = __base_remove_element_value;
	// a->remove_all = __base_remove_element_all;
	// array(a);
	return (a);
}

// rdi, rsi, rdx, rcx, r8, e r9
t_array *array(t_array *array)
{
	unsigned long long int rsi_value = 0;
	(*this()) = array;
	asm volatile("movq %%rsi, %0\n\t"
				 : "=r"(rsi_value)
				 :
				 : "memory");
	return (array);
}
