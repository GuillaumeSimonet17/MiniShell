/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:33:30 by marobert          #+#    #+#             */
/*   Updated: 2023/04/05 15:51:53 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static size_t	ft_longlen(long long nb)
{
	if (nb < -9)
		return (ft_longlen((nb / 10) * -1) + 2);
	if (nb > 9)
		return (ft_longlen(nb / 10) + 1);
	if (nb < 0)
		return (2);
	return (1);
}

static long long	ft_atof(const char *str)
{
	int				i;
	long long		sign;
	long long		nb;

	nb = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0') * sign;
		i++;
	}
	return (nb);
}

static int	atof_valid(const char *str)
{
	int			i;
	int			size;
	long long	tmp;
	int			start_zero;

	i = 0;
	start_zero = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
	{
		start_zero++;
		i++;
	}
	while (ft_isdigit(str[i]))
		i++;
	size = (int)ft_strlen(str);
	tmp = ft_atof(str);
	if (tmp == 0)
		start_zero -= 1;
	return (i == size && (ft_longlen(tmp) + start_zero == (size_t)i));
}

int	bt_exit(t_list *argv)
{
	if (!argv || !argv->next || ((t_str *)argv->next->content)->type != STR)
	{
		ft_dprintf(2, "exit\n");
		exit(g_err_code);
	}
	argv = argv->next;
	ft_dprintf(2, "exit\n");
	if (atof_valid(((t_str *)argv->content)->str))
	{
		if (!argv->next || ((t_str *)argv->next->content)->type != STR)
			exit((int)ft_atof(((t_str *)argv->content)->str) % 256);
		g_err_code = 1;
		return (ft_dprintf(2, "exit: %s\n", TOO_MANY_ARGS));
	}
	ft_dprintf(2, "exit: %s: %s\n", ((t_str *)argv->content)->str, NUM_ARG_REQ);
	exit(2);
}
//max exit : 9223372036854775808
