/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:56:15 by marobert          #+#    #+#             */
/*   Updated: 2023/03/13 10:57:24 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/lst_utils.h"

t_list	*sort_lst(t_list *lst)
{
	t_list	*tmp;
	t_list	*tmp2;
	char	*tmp_str;

	tmp = lst;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (ft_strncmp(tmp->content, tmp2->content, -1) > 0)
			{
				tmp_str = tmp->content;
				tmp->content = tmp2->content;
				tmp2->content = tmp_str;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (lst);
}
