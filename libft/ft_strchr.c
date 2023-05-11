/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:46:03 by gusimone          #+#    #+#             */
/*   Updated: 2022/11/12 16:14:49 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	u;

	i = 0;
	u = (unsigned char)c;
	while (s[i])
	{
		if (u == ((char *)s)[i])
			return ((char *)s + i);
		i++;
	}
	if (u == ((char *)s)[i])
		return ((char *)s + i);
	return (NULL);
}
