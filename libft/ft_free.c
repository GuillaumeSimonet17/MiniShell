/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:42:03 by marobert          #+#    #+#             */
/*   Updated: 2023/02/21 15:42:03 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(t_m_free *m_free)
{
	t_free	*tmp;

	while (m_free->list)
	{
		tmp = m_free->list;
		m_free->list = m_free->list->next;
		if (tmp->ptr)
			free(tmp->ptr);
		free(tmp);
	}
	free(m_free);
}
