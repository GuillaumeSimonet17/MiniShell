/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_xc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:14:39 by marobert          #+#    #+#             */
/*   Updated: 2022/11/11 12:48:22 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	format_xc(va_list *valist, int fd)
{
	return ((int) ft_putnbr_base_fd(va_arg(*valist, unsigned int), \
			BASE_HEXA_U, fd));
}
