/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:15:49 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/25 14:24:18 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Engine.h"

int free_list(void **values)
{
	int i;

	if (values)
	{
		i = -1;
		while (values[++i])
			free(values[i]);
		free(values);
		return (i);
	}
	return (0);
}

void *ft_calloc(size_t __size)
{
	void *v;
	unsigned char *temp;

	if (__size < 1)
		return (NULL);
	v = malloc(__size);
	if (!v)
		engine()->destroy("Error");
	temp = (unsigned char *)v;
	while (__size-- > 0)
		*(temp++) = (unsigned char)0;
	return (v);
}
