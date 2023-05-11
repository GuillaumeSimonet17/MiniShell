/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:28:49 by marobert          #+#    #+#             */
/*   Updated: 2022/12/15 10:49:58 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	format_u(va_list *valist, int fd)
{
	unsigned int	nb;

	nb = va_arg(*valist, unsigned int);
	ft_putunbr_fd(nb, fd);
	return ((int)ft_ulllen(nb));
}
