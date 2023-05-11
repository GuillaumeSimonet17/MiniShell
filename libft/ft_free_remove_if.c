/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:41:53 by marobert          #+#    #+#             */
/*   Updated: 2023/02/21 15:41:53 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_remove_if(t_free **begin_list, void *ptr_ref)
{
	t_free	*to_free;

	if (*begin_list)
	{
		if ((*begin_list)->ptr == ptr_ref)
		{
			to_free = *begin_list;
			*begin_list = (*begin_list)->next;
			if (to_free->ptr)
				free(to_free->ptr);
			free(to_free);
			ft_free_remove_if(begin_list, ptr_ref);
		}
		else
			ft_free_remove_if(&(*begin_list)->next, ptr_ref);
	}
}

void	ft_free_remove(t_m_free *m_free, void *ptr)
{
	ft_free_remove_if(&m_free->list, ptr);
}
