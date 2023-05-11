/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:34:40 by gusimone          #+#    #+#             */
/*   Updated: 2023/04/15 16:59:56 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_long(int nb);
static char	*ft_itoa_min(int n);
static char	*ft_itoa_zero(int n);

static int	ft_long(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb > 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

static char	*ft_itoa_min(int n)
{
	char			*str;
	int				i;
	unsigned int	nu;

	i = 11;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (0);
	str[i--] = 0;
	str[0] = '-';
	nu = n;
	while (nu > 0)
	{
		str[i] = 48 + (nu % 10);
		nu /= 10;
		i--;
	}
	return (str);
}

static char	*ft_itoa_zero(int n)
{
	char	*str;

	str = malloc(sizeof(char) * n + 2);
	if (!str)
		return (0);
	str[0] = '0';
	str[1] = 0;
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_long(n);
	if (n == -2147483648)
		return (ft_itoa_min(n));
	if (n == 0)
		return (ft_itoa_zero(n));
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = 0;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[i--] = 48 + (n % 10);
		n /= 10;
	}
	return (str);
}
