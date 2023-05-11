/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:04:17 by marobert          #+#    #+#             */
/*   Updated: 2023/03/30 15:08:17 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_next(t_list *lst, t_list *to_add)
{
	t_list	*tmp;

	if (!lst || !to_add)
		return ;
	tmp = lst->next;
	lst->next = to_add;
	if (tmp)
		tmp->before = ft_lstlast(to_add);
	ft_lstlast(to_add)->next = tmp;
	to_add->before = lst;
}
