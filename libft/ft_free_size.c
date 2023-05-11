/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:41:39 by marobert          #+#    #+#             */
/*   Updated: 2023/02/21 15:41:39 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free_size(t_m_free *m_free)
{
	int	i;

	i = 0;
	if (m_free->list)
	{
		while (m_free->list->next)
		{
			i++;
			m_free->list = m_free->list->next;
		}
		i++;
	}
	return (i);
}
