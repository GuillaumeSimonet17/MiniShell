/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:35:04 by gusimone          #+#    #+#             */
/*   Updated: 2023/01/02 16:27:22 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_address(unsigned long long nb, char *base, int *ret)
{
	unsigned long long	base_len;

	base_len = ft_ull_strlen((char *)base);
	if (nb >= base_len)
		ft_address(nb / base_len, base, ret);
	ft_putchar_ret((base[nb % base_len]), ret);
}
