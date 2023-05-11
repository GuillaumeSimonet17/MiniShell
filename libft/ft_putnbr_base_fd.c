/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:54:33 by marobert          #+#    #+#             */
/*   Updated: 2022/12/15 11:07:44 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rec_putnbr_base_fd(unsigned int nb, char *base, int fd)
{
	if (nb >= ft_strlen(base))
		ft_rec_putnbr_base_fd(nb / ft_strlen(base), base, fd);
	ft_putchar_fd(base[(nb % ft_strlen(base))], fd);
}

int	ft_check_forbidden(const char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base[0] || !base[1])
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

ssize_t	ft_putnbr_base_fd(long long nb, char *base, int fd)
{
	size_t	nb2;

	if (ft_strlen(base) <= 1 || !ft_check_forbidden(base))
		return (-1);
	else if (nb < 0)
	{
		nb2 = (size_t) nb * -1;
		ft_putchar_fd('-', fd);
	}
	else
		nb2 = (size_t) nb;
	ft_rec_putnbr_base_fd(nb2, base, fd);
	return (ft_ulllen(nb));
}
