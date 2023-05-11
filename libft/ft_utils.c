/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:19:27 by gusimone          #+#    #+#             */
/*   Updated: 2023/01/02 16:27:18 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_ret(char c, int *ret)
{
	write(1, &c, 1);
	*ret += 1;
}

unsigned long long	ft_ull_strlen(char *s)
{
	unsigned long long	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_ret(char *str, int *ret)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		*ret += 6;
		return ;
	}
	while (str[i])
	{
		ft_putchar_ret(str[i], ret);
		i++;
	}
}

void	ft_putnbr_ret(int nb, int *ret)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		*ret += 11;
		return ;
	}
	if (nb < 0)
	{
		ft_putchar_ret('-', ret);
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr_ret(nb / 10, ret);
	ft_putchar_ret((nb % 10) + 48, ret);
}

void	ft_putnbr_u_ret(unsigned int nb, int *ret)
{
	if (nb > 9)
		ft_putnbr_ret(nb / 10, ret);
	ft_putchar_ret((nb % 10) + 48, ret);
}
