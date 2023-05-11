/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:12:35 by marobert          #+#    #+#             */
/*   Updated: 2023/04/17 20:03:09 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	builtin_bis(t_list *cmds, t_list **envp, t_pip *p)
{
	if (!ft_strncmp(((t_str *)cmds->content)->str, "echo", -1))
		return (echo(cmds, p));
	if (!ft_strncmp(((t_str *)cmds->content)->str, "cd", -1))
	{
		if (p->nb_cmd > 1)
			return (0);
		return (cd(cmds, envp), 0);
	}
	if (!ft_strncmp(((t_str *)cmds->content)->str, "pwd", -1))
		return (pwd(p), 0);
	else
		return (-1);
}

int	exec_cmd(t_list *cmds, t_list **envp, t_pip *p)
{
	if (builtin_bis(cmds, envp, p) != -1)
		return (0);
	if (!ft_strncmp(((t_str *)cmds->content)->str, "export", -1))
	{
		if (p->nb_cmd > 1)
			return (0);
		return (export(cmds, envp, p), 0);
	}
	if (!ft_strncmp(((t_str *)cmds->content)->str, "unset", -1))
	{
		if (p->nb_cmd > 1)
			return (0);
		return (unset(cmds, envp), 0);
	}
	if (!ft_strncmp(((t_str *)cmds->content)->str, "env", -1))
		return (env(*envp, p), 0);
	if (!ft_strncmp(((t_str *)cmds->content)->str, "exit", -1))
	{
		if (p->nb_cmd > 1)
			return (0);
		return (bt_exit(cmds), 0);
	}
	else
		return (1);
}

void	multi_cmds(t_pip *p, t_list *cmds, t_list **env, struct sigaction *sa)
{
	t_list	*tmp;

	p->index = 0;
	while (cmds)
	{
		tmp = cmds->content;
		init_and_close_files(p);
		get_infile_outfile(cmds, p);
		is_here_doc(p, cmds, tmp);
		if (p->hd == 1)
			hd_one_cmd(p, cmds, *env);
		if (exec_cmd(cmds->content, env, p) == 1)
			child_process(p, cmds, *env, sa);
		(p->index)++;
		cmds = cmds->next;
	}
}

void	simple_cmd(t_pip *p, t_list *cmds, t_list **env, struct sigaction *sa)
{
	t_list	*tmp;

	tmp = cmds->content;
	is_here_doc(p, cmds, tmp);
	get_infile_outfile(cmds, p);
	if (p->hd == 1)
		hd_one_cmd(p, cmds, *env);
	if (exec_cmd(cmds->content, env, p) == 1)
		child_process(p, cmds, *env, sa);
}

void	child_process(t_pip *p, t_list *cmds, t_list *envp, \
					struct sigaction *sa)
{
	char				**env;

	p->pid = fork();
	if (p->pid == -1)
	{
		ft_putstr_fd(": error fork\n", 2);
		return ;
	}
	if (p->pid > 0)
		handle_inception(cmds, sa);
	if (p->pid == 0)
	{
		all_dup(p);
		close_pipes(p);
		env = lst_in_tab(envp);
		p->cmd = NULL;
		p->cmd_args = lst_in_tab2(cmds);
		if (!p->cmd_args)
			exit(1);
		check_error(p);
		get_cmd_path(p);
		check_err_infile(p);
		execve(p->cmd, p->cmd_args, env);
	}
}
