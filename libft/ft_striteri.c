/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:47:17 by gusimone          #+#    #+#             */
/*   Updated: 2022/11/11 20:24:12 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	size_t			j;

	if (!s)
		return ;
	j = ft_strlen((char *)s);
	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (i != j)
	{
		(*f)(i, s);
		i++;
		s++;
	}
}
