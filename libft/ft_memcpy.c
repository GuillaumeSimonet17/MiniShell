/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:05:23 by gusimone          #+#    #+#             */
/*   Updated: 2022/11/19 16:33:43 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size )
{
	unsigned char	*dest;
	unsigned char	*src;

	if (destination == NULL && source == NULL)
		return (NULL);
	src = (unsigned char *)source;
	dest = (unsigned char *)destination;
	if (size == 0)
		return ((void *)dest);
	while (size--)
		*dest++ = *src++;
	return (destination);
}
