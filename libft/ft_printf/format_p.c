/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:28:49 by marobert          #+#    #+#             */
/*   Updated: 2022/11/11 12:57:31 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	format_p_worker(unsigned long long nb, int fd)
{
	if (nb > 15)
		format_p_worker(nb / 16, fd);
	nb %= 16;
	if (nb > 9)
		ft_putchar_fd(nb - 10 + 'a', fd);
	else
		ft_putchar_fd(nb + '0', fd);
}

int	format_p(va_list *valist, int fd)
{
	unsigned long long	nb;

	nb = va_arg(*valist, unsigned long long);
	ft_putstr_fd("0x", fd);
	format_p_worker(nb, fd);
	return ((int)ft_ulllen(nb));
}
