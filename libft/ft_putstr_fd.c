/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:44:49 by marobert          #+#    #+#             */
/*   Updated: 2022/12/15 10:43:18 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

ssize_t	ft_putstr_fd(char *s, int fd)
{
	int		i;

	if (!s)
		return (ft_putstr_fd("(null)", fd));
	i = 0;
	while (s[i])
		i++;
	return (write(fd, s, i));
}
