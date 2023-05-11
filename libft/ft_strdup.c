/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:46:34 by gusimone          #+#    #+#             */
/*   Updated: 2023/03/03 15:08:26 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_m(const char *source, t_m_free *m_free)
{
	int		i;
	char	*dest;

	dest = ft_free_malloc(m_free, sizeof(char) * \
						(ft_strlen((char *)source) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (source[i])
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strdup(const char *source)
{
	int		i;
	char	*dest;

	dest = malloc(sizeof(char) * (ft_strlen((char *)source) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (source[i])
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strndup(const char *s1, size_t len)
{
	size_t	i;
	char	*dup;

	i = 0;
	while (s1[i] && i < len)
		i++;
	dup = malloc(sizeof(char) * (i + 1));
	if (dup == NULL)
		return (dup);
	i = 0;
	while (s1[i] && i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}
