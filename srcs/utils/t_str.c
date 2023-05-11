/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_str.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:53:55 by marobert          #+#    #+#             */
/*   Updated: 2023/02/28 10:31:44 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/t_str.h"

t_str	*new_str(char *content)
{
	t_str	*elem;

	elem = malloc(sizeof(t_str));
	if (!elem)
		return (NULL);
	if (!ft_strncmp(">", content, -1))
		elem->type = CHEV_R;
	else if (!ft_strncmp(">>", content, -1))
		elem->type = CHEV_2R;
	else if (!ft_strncmp("<", content, -1))
		elem->type = CHEV_L;
	else if (!ft_strncmp("<<", content, -1))
		elem->type = CHEV_2L;
	else
		elem->type = STR;
	elem->str = content;
	return (elem);
}

void	free_t_str(void *elem)
{
	free(((t_str *)elem)->str);
	free(elem);
}
