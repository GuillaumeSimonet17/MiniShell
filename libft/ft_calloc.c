/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:31:43 by gusimone          #+#    #+#             */
/*   Updated: 2022/11/13 15:10:25 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	unsigned char	*bloc;
	size_t			i;

	i = 0;
	if (elementSize != 0 && elementCount > SIZE_MAX / elementSize)
		return (NULL);
	bloc = (void *)malloc((elementCount * elementSize));
	if (!bloc)
		return (NULL);
	while (i < elementCount * elementSize)
	{
		bloc[i] = 0;
		i++;
	}
	return (bloc);
}
