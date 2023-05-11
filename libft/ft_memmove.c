/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:41:39 by gusimone          #+#    #+#             */
/*   Updated: 2022/11/12 15:12:41 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove( void *destination, const void *source, size_t size)
{
	size_t	i;

	i = 0;
	if (destination == NULL && source == NULL)
		return (NULL);
	if (destination < source)
	{
		while (i < size)
		{
			((unsigned char *)destination)[i] = ((unsigned char *)source)[i];
			i++;
		}
	}
	else
	{
		i = size;
		while (i > 0)
		{
			((unsigned char *)destination)[i - 1] = ((unsigned char *)source) \
			[i - 1];
			i--;
		}
	}
	return ((void *)destination);
}
