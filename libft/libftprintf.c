/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:16:57 by gusimone          #+#    #+#             */
/*   Updated: 2023/04/05 10:16:31 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_if_conv(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' \
	|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

void	ft_base(int nb, char *base, int *ret)
{
	unsigned int	n;
	unsigned long	base_len;

	base_len = ft_ull_strlen((char *)base);
	if (nb == 16)
	{
		ft_putstr_ret("10", ret);
		return ;
	}
	if (nb == -2147483648)
	{
		ft_putstr_ret("80000000", ret);
		return ;
	}
	n = nb;
	if (n > base_len)
		ft_base(n / base_len, base, ret);
	ft_putchar_ret((base[n % base_len]), ret);
}

void	ft_which_one(char c, va_list arg, int *ret)
{
	if (c == 'c')
		ft_putchar_ret(va_arg(arg, int), ret);
	else if (c == 's')
		ft_putstr_ret(va_arg(arg, char *), ret);
	else if (c == 'd' || c == 'i')
		ft_putnbr_ret(va_arg(arg, int), ret);
	else if (c == 'u')
		ft_putnbr_u_ret(va_arg(arg, int), ret);
	else if (c == 'x')
		ft_base(va_arg(arg, int), "0123456789abcdef", ret);
	else if (c == 'X')
		ft_base(va_arg(arg, int), "0123456789ABCDEF", ret);
	else if (c == 'p')
	{
		ft_putstr_ret("0x", ret);
		ft_address((unsigned long long)va_arg(arg, unsigned long long), \
		"0123456789abcdef", ret);
	}
	else if (c == '%')
		ft_putchar_ret('%', ret);
}

int	ft_scan_printf(int i, char *str, int ret, va_list arg)
{
	while (str[i])
	{
		while (str[i] == '%' && ft_if_conv(str[i + 1]))
		{
			i++;
			ft_which_one(str[i], arg, &ret);
			if (str [i + 1])
				i++;
			else
				return (ret);
		}
		if (str[i] == '%' && str[i + 1] == '%')
		{
			i++;
			if (str[i] == '%' && str[i + 1] == '%')
				i++;
			ft_putchar_ret('%', &ret);
		}
		if (str[i] == '%' && str[i + 1] == ' ' && ft_if_conv(str[i + 2]) == 0)
			i += 2;
		else
			ft_putchar_ret(str[i], &ret);
		i++;
	}
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		ret;

	if (write(1, NULL, 0) != 0)
		return (-1);
	va_start(arg, str);
	ret = 0;
	i = 0;
	ret = ft_scan_printf(i, (char *)str, ret, arg);
	va_end(arg);
	return (ret);
}
