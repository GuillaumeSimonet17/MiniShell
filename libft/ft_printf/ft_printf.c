/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:51:52 by marobert          #+#    #+#             */
/*   Updated: 2023/04/05 10:15:39 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_format(const char format, va_list *valist, int fd)
{
	if (format == 'c')
		return (format_c(valist, fd));
	else if (format == 's')
		return (format_s(valist, fd));
	else if (format == 'p')
		return (format_p(valist, fd));
	else if (format == 'i' || format == 'd')
		return (format_di(valist, fd));
	else if (format == 'u')
		return (format_u(valist, fd));
	else if (format == 'x')
		return (format_x(valist, fd));
	else if (format == 'X')
		return (format_xc(valist, fd));
	else if (format == '%')
		ft_putchar_fd('%', fd);
	return (1);
}

int	ft_dprintf(int fd, const char *text, ...)
{
	int		i;
	va_list	valist;
	int		printed;

	if (write(fd, 0, 0) == -1)
		return (-1);
	printed = 0;
	va_start(valist, text);
	i = 0;
	while (text[i])
	{
		if (text[i] != '%')
		{
			ft_putchar_fd(text[i], fd);
			printed++;
		}
		else
		{
			i++;
			printed += ft_format(text[i], &valist, fd);
		}
		i++;
	}
	va_end(valist);
	return (printed);
}
