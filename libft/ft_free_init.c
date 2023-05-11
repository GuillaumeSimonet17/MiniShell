/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:41:50 by marobert          #+#    #+#             */
/*   Updated: 2023/03/28 14:16:01 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_m_free	*ft_free_init(void)
{
	t_m_free	*m_free;

	m_free = (t_m_free *)malloc(sizeof(t_m_free));
	if (!m_free)
		exit (1);
	m_free->list = NULL;
	return (m_free);
}
