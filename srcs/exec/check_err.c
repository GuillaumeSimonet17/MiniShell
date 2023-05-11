/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:49:05 by gusimone          #+#    #+#             */
/*   Updated: 2023/04/20 17:23:39 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "main.h"
#include <dirent.h>

int	cmd_error(char *s)
{
	if (!s || s[0] == 0)
		return (-3);
	if (s[0] == '.' && (s[1] != '/' || !s[1]))
		return (-1);
	if (s[0] == '/')
	{
		if (access(s, F_OK) != 0)
			return (-2);
	}
	if (s[0] == '.' && s[1] == '/' )
	{
		if (access(s, F_OK | X_OK) == 0 && opendir(s) != 0)
			return (-4);
		else if (access(s, F_OK) == 0 && access(s, X_OK) != 0)
			return (-5);
	}
	return (0);
}

void	check_error(t_pip *p)
{
	if (p->cmd_args[0] == NULL)
		exit(1);
	if (cmd_error(p->cmd_args[0]) != 0)
		ft_putstr_fd(p->cmd_args[0], 2);
	if (cmd_error(p->cmd_args[0]) == -1 || cmd_error(p->cmd_args[0]) == -3)
		ft_putstr_fd(": command not found\n", 2);
	else if (cmd_error(p->cmd_args[0]) == -2)
		ft_putstr_fd(": No such file or directory\n", 2);
	else if (cmd_error(p->cmd_args[0]) == -4)
	{
		ft_putstr_fd(": Is a directory\n", 2);
		exit(126);
	}
	else if (cmd_error(p->cmd_args[0]) == -5)
	{
		ft_putstr_fd(": Permission denied\n", 2);
		exit(126);
	}
	if (cmd_error(p->cmd_args[0]) != 0)
		exit(127);
}

void	check_err_infile(t_pip *p)
{
	if (p->err_infile == 1)
	{
		p->err_infile = 0;
		exit(1);
	}
	if (p->index == (int)p->nb_cmd - 1 && p->err_outfile == 1)
	{
		p->err_outfile = 0;
		exit(1);
	}
}
