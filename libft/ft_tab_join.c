/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:41:22 by marobert          #+#    #+#             */
/*   Updated: 2023/02/21 15:41:22 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tab_join(char **tab)
{
	size_t	i;
	size_t	final_len;
	char	*str;

	if (!tab)
		return (NULL);
	i = 0;
	final_len = 1;
	while (tab[i])
	{
		final_len += ft_strlen(tab[i]);
		i++;
	}
	str = malloc(sizeof(char) * (final_len + 1));
	if (!str)
		return (NULL);
	str[0] = 0;
	i = 0;
	while (tab[i])
	{
		ft_strlcat(str, tab[i], final_len);
		i++;
	}
	str[final_len] = 0;
	return (str);
}
