/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:21:05 by gusimone          #+#    #+#             */
/*   Updated: 2022/11/21 16:58:54 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	u;
	int				n;

	u = (unsigned char)c;
	n = ft_strlen((char *)s);
	if (s[n] == u)
		return ((char *)s + n);
	while (n >= 0)
	{
		if (s[n] == u)
			return ((char *)s + n);
		n--;
	}
	return (0);
}
