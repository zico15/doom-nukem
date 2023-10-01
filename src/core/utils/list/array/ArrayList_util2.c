// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_array.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/02/20 13:51:06 by edos-san          #+#    #+#             */
// /*   Updated: 2022/02/20 13:51:06 by edos-san         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */
// #include <ft_base_array.h>
// #include <ft_base_array_util.h>
#include "ArrayList.h"

typedef struct s_array_private t_array_private;

t_node *__set_array(int index, void *value)
{
    t_array_private *a;

    a = *this();
    if (!a || index < 0 || index >= a->size)
        return (NULL);
    if (a->array[index]->destroy)
        a->array[index]->destroy(a->array[index]->value);
    a->array[index]->value = value;
    return (a->array[index]);
}