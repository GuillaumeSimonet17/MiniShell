/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:51:33 by marobert          #+#    #+#             */
/*   Updated: 2022/12/09 14:56:13 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_intlen(int nb)
{
	if (nb < -9)
		return (ft_intlen((nb / 10) * -1) + 2);
	if (nb > 9)
		return (ft_intlen(nb / 10) + 1);
	if (nb < 0)
		return (2);
	return (1);
}
