/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:04:39 by gusimone          #+#    #+#             */
/*   Updated: 2023/04/17 20:15:23 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	process(t_pip *p, t_list *cmds, t_list **env, struct sigaction *sa)
{
	p->index = 0;
	p->infile = 0;
	p->outfile = 0;
	if (p->nb_cmd > 1)
		multi_cmds(p, cmds, env, sa);
	else
		simple_cmd(p, cmds, env, sa);
	close_pipes(p);
	while (waitpid(-1, &g_err_code, 0) != -1)
		;
	if (g_err_code >= 256)
		g_err_code /= 256;
}

int	multi_pipes(t_list *cmds, t_list **env, struct sigaction *sa)
{
	t_pip	p;

	p.m_free = ft_free_init();
	p.nb_cmd = get_nb_cmds(cmds);
	if (p.nb_cmd == 0)
		p.nb_cmd = 1;
	p.nb_pipe = 2 * (p.nb_cmd - 1);
	p.pipe = ft_free_malloc(p.m_free, sizeof(int) * p.nb_pipe);
	if (!p.pipe)
		return (1);
	p.env_path = get_env_value("PATH", *env);
	if (p.env_path != NULL)
	{
		p.cmd_paths = ft_split(p.env_path, ':');
		if (!p.cmd_paths)
			return (free_pipe(&p), 1);
	}
	else
		p.cmd_paths = NULL;
	create_pipes(&p);
	process(&p, cmds, env, sa);
	parent_free(&p);
	ft_free(p.m_free);
	return (0);
}
