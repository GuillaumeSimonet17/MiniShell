/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 12:06:29 by gusimone          #+#    #+#             */
/*   Updated: 2023/04/20 16:30:16 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	init_and_close_files(t_pip *p)
{
	if (p->infile > 0)
		close(p->infile);
	if (p->outfile > 0)
		close(p->outfile);
	p->infile = 0;
	p->outfile = 0;
}

void	get_infile(t_pip *p, t_list *tmp)
{
	if (p->got_infile == 1)
		close(p->infile);
	tmp = tmp->next;
	p->infile_name = ((t_str *)(tmp->content))->str;
	p->infile = open(p->infile_name, O_RDONLY);
	if (p->infile == -1)
	{
		ft_putstr_fd(p->infile_name, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		p->err_infile = 1;
	}
	else
	{
		if (p->err_infile == 1)
			close(p->infile);
		p->got_infile = 1;
	}
}

void	get_out_trunc(t_pip *p, t_list *tmp)
{
	if (p->err_infile == 1)
		return ;
	if (p->got_outfile == 1)
		close(p->outfile);
	tmp = tmp->next;
	p->outfile_name = ((t_str *)(tmp->content))->str;
	p->outfile = open(p->outfile_name,
			O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (p->outfile == -1)
	{
		ft_putstr_fd(p->outfile_name, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		p->err_outfile = 1;
	}
	else
		p->got_outfile = 1;
}

void	get_out_append(t_pip *p, t_list *tmp)
{
	if (p->err_infile == 1)
		return ;
	if (p->got_outfile == 1)
		close(p->outfile);
	tmp = tmp->next;
	p->outfile_name = ((t_str *)(tmp->content))->str;
	p->outfile = open(p->outfile_name,
			O_RDWR | O_CREAT | O_APPEND, 0644);
	if (p->outfile == -1)
	{
		ft_putstr_fd(p->outfile_name, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		p->err_outfile = 1;
	}
	p->got_outfile = 1;
}

int	get_infile_outfile(t_list *cmds, t_pip *p)
{
	t_list	*tmp;

	p->got_outfile = 0;
	p->got_infile = 0;
	p->err_infile = 0;
	p->err_outfile = 0;
	tmp = cmds->content;
	while (tmp)
	{
		if (((t_str *)(tmp->content))->type == 1)
			get_infile(p, tmp);
		if (((t_str *)(tmp->content))->type == 4)
			get_out_append(p, tmp);
		if (((t_str *)(tmp->content))->type == 2)
			get_out_trunc(p, tmp);
		tmp = tmp->next;
	}
	return (1);
}
