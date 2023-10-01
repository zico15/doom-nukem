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


static void __for_each(void (*fun)(t_node *node, void *v), void *o)
{
	t_node *e;
	t_array *a;

	a = *this();
	if (!a || !fun)
		return;
	e = a->begin;
	while (e)
	{
		fun(e, o);
		e = e->next;
	}
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
	if (!a->begin)
		a->begin = e;
	else
	{
		e->prev = a->end;
		a->end->next = e;
	}
	a->end = e;
	a->size++;
	return (e);
}

static t_node *__remove(void *value)
{
	t_node *node;
	t_array *a;

	a = *this();
	if (!a || !value)
		return (NULL);
	node = a->begin;
	while (node)
	{
		if (a->cmp(node->value, value) && a->size-- >= 0)
		{
			if (a->end == node)
				a->end = node->prev;
			if (node->prev)
				node->prev->next = node->next;
			else
			{
				a->begin = node->next;
				a->begin->prev = NULL;
			}
			return (node);
		}
		node = node->next;
	}
	return (NULL);
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

t_array *array(t_array *array)
{
	(*this()) = array;
	return (array);
}
