/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:53:29 by gusimone          #+#    #+#             */
/*   Updated: 2023/05/11 13:45:31 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <string.h>
#include "parsing.h"

void	check_endword(t_pip *p, int i)
{
	p->n = ft_itoa(i);
	p->s = ft_strjoin(".", p->n);
	free(p->n);
	p->tmp_fd = open(p->s, O_RDWR | O_CREAT | O_APPEND, 0777);
	free(p->s);
	p->line = readline("> ");
	p->exp = 0;
	if (p->end[0] == '"')
	{
		p->exp = 1;
		p->end = &p->end[1];
	}
}

void	exec_hd(t_pip *p, int i, int nb, t_list *env)
{
	int	fd;

	check_endword(p, i);
	while (p->line && ft_strncmp(p->line, p->end, -1) != 0)
	{
		if (p->exp != 1)
			p->line = replace_all_vars(p->line, env);
		if (nb - 1 == i)
			fd = p->fdhd[1];
		else
			fd = p->tmp_fd;
		ft_putstr_fd(p->line, fd);
		ft_putstr_fd("\n", fd);
		free(p->line);
		p->line = readline("> ");
	}
	close(p->tmp_fd);
	free(p->line);
}

int	nb_hd(t_list *cmds)
{
	t_list	*tmp;
	int		nb;

	nb = 0;
	tmp = cmds->content;
	while (tmp)
	{
		if (((t_str *)tmp->content)->type == 3)
			nb++;
		tmp = tmp->next;
	}
	return (nb);
}

void	do_all_hd(t_pip *p, t_list *tmp, int nb, t_list *env)
{
	int	i;

	i = 0;
	while (tmp && ((t_str *)tmp->content)->type == 3)
	{
		p->end = ((t_str *)tmp->next->content)->str;
		exec_hd(p, i, nb, env);
		tmp = tmp->next->next;
		i++;
		p->n2 = ft_itoa(i - 1);
		p->s2 = ft_strjoin(".", p->n2);
		if (tmp && ((t_str *)tmp->content)->type == 3)
			unlink(p->s2);
		free(p->s2);
		free(p->n2);
	}
	p->n2 = ft_itoa(i - 1);
	p->s2 = ft_strjoin(".", p->n2);
	free(p->n2);
	unlink(p->s2);
	free(p->s2);
}

void	hd_one_cmd(t_pip *p, t_list *cmds, t_list *env)
{
	t_list				*tmp;
	struct sigaction	sa;

	tmp = cmds->content;
	p->nb = nb_hd(cmds);
	while (((t_str *)tmp->content)->type != 3)
		tmp = tmp->next;
	pipe(p->fdhd);
	p->pid = fork();
	if (p->pid == -1)
		return ;
	if (p->pid == 0)
	{
		init_heredoc_sig(&sa);
		close(p->fdhd[0]);
		do_all_hd(p, tmp, p->nb, env);
		if (p->outfile > 0)
			close(p->outfile);
		close(p->fdhd[1]);
		exit(0);
	}
	close(p->fdhd[1]);
	while (waitpid(-1, NULL, 0) != -1)
		;
	// close(p->fdhd[0]);
}
