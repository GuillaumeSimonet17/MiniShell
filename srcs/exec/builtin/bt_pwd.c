/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 21:20:40 by marobert          #+#    #+#             */
/*   Updated: 2023/04/17 18:34:39 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	pwd(t_pip *p)
{
	char	path[PATH_MAX];

	g_err_code = 0;
	if (!getcwd(path, PATH_MAX))
		return (ft_dprintf(STDERR_FILENO, ERROR_WD));
	if (p->nb_cmd > 1)
	{
		ft_putstr_fd(path, p->pipe[2 * p->index + 1]);
		ft_putstr_fd("\n", p->pipe[2 * p->index + 1]);
	}
	else
		printf("%s\n", path);
	return (0);
}
