/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:28:49 by marobert          #+#    #+#             */
/*   Updated: 2022/12/15 11:05:56 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	format_x(va_list *valist, int fd)
{
	return ((int) ft_putnbr_base_fd(va_arg(*valist, unsigned int), \
			BASE_HEXA_L, fd));
}
