/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:56:55 by gusimone          #+#    #+#             */
/*   Updated: 2022/11/12 15:17:48 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char c, char const *set);

static int	ft_check(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		i;
	int		a;
	int		k;

	i = 0;
	a = 0;
	if (!s1)
		return (NULL);
	while (ft_check(s1[i], set) == 1)
		i++;
	k = ft_strlen((char *)s1) - 1;
	while (ft_check(s1[k], set) == 1 && s1[i])
		k--;
	new = malloc(sizeof(char) * ((k - i + 1) + 1));
	if (!new)
		return (NULL);
	while (i <= k)
		new[a++] = s1[i++];
	new[a] = 0;
	return (new);
}
