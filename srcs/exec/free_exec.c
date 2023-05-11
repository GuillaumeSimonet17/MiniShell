/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:38:06 by gusimone          #+#    #+#             */
/*   Updated: 2023/03/21 11:14:41 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	parent_free(t_pip *p)
{
	int	i;

	i = 0;
	if (p->infile > 0)
		close(p->infile);
	if (p->outfile > 0)
		close(p->outfile);
	if (p->cmd_paths)
	{
		while (p->cmd_paths[i])
		{
			free(p->cmd_paths[i]);
			i++;
		}
		free(p->cmd_paths);
	}
}

void	ft_free_child(t_pip *p)
{
	int	i;

	i = 0;
	if (p->cmd_args)
	{
		while (p->cmd_args[i])
		{
			free(p->cmd_args[i]);
			i++;
		}
		free(p->cmd_args);
	}
	if (p->cmd)
		free(p->cmd);
}

void	free_pipe(t_pip *p)
{
	close(p->infile);
	close(p->outfile);
	free(p->pipe);
	exit(1);
}
