/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:41:47 by marobert          #+#    #+#             */
/*   Updated: 2023/03/28 14:19:53 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free_add_value(t_m_free *m_free, t_free *el, t_free *tmp)
{
	if (m_free->list)
	{
		tmp = m_free->list;
		while (tmp->next)
		{
			if (tmp->ptr == el->ptr)
				return (0);
			tmp = tmp->next;
		}
		if (tmp->ptr == el->ptr)
			return (0);
		tmp->next = el;
		return (1);
	}
	else
	{
		m_free->list = el;
		return (1);
	}
}

int	ft_free_add(t_m_free *m_free, void *ptr)
{
	t_free	*el;
	t_free	*tmp;

	if (ptr)
	{
		el = malloc(sizeof(t_free));
		if (!el)
		{
			ft_free(m_free);
			exit(1);
		}
		tmp = NULL;
		el->ptr = ptr;
		el->next = NULL;
		if (ft_free_add_value(m_free, el, tmp))
			return (1);
		else
			free(el);
	}
	return (0);
}
