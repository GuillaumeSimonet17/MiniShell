/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:57:35 by gusimone          #+#    #+#             */
/*   Updated: 2022/12/16 21:01:54 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen((char *)s) - start)
		len = ft_strlen((char *)s) - start;
	if (start > ft_strlen((char *)s))
	{
		new = malloc(sizeof(char) * 1);
		if (!new)
			return (NULL);
		new[i] = 0;
		return (new);
	}
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (s[start] && i < len)
		new[i++] = s[start++];
	new[i] = 0;
	return (new);
}
