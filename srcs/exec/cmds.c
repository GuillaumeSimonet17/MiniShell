/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 12:05:27 by gusimone          #+#    #+#             */
/*   Updated: 2023/04/03 13:24:44 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	get_nb_cmds(t_list *cmds)
{
	t_list	*tmp;
	int		i;

	i = 0;
	while (cmds)
	{
		tmp = cmds->content;
		if (((t_str *)(tmp->content))->type != 0 && \
			((t_str *)(tmp->content))->type != 3)
			break ;
		i++;
		cmds = cmds->next;
	}
	return (i);
}

char	*get_cmd(char **path, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*path)
	{
		tmp = ft_strjoin(*path, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, F_OK) == 0)
			return (command);
		free(command);
		path++;
	}
	return (NULL);
}

void	get_cmd_path(t_pip *p)
{
	if (is_contain(p->cmd_args[0], '/') == 0)
	{
		if (!p->env_path)
		{
			ft_putstr_fd(p->cmd_args[0], 2);
			ft_putstr_fd(": command not found\n", 2);
			exit(127);
		}
		p->cmd = get_cmd(p->cmd_paths, p->cmd_args[0]);
	}
	else
		p->cmd = p->cmd_args[0];
	if (!p->cmd || access(p->cmd, F_OK) != 0)
	{
		if (p->cmd && ((p->cmd[0] == '.' && p->cmd[1] == '/')))
		{
			ft_putstr_fd(p->cmd_args[0], 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			exit(127);
		}
		ft_putstr_fd(p->cmd_args[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(127);
	}
}
