/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:46:02 by marobert          #+#    #+#             */
/*   Updated: 2022/12/15 11:01:49 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putunbr_fd(unsigned long long nb, int fd)
{
	if (nb > 9)
		ft_putunbr_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
	return ((ssize_t)ft_ulllen(nb));
}
