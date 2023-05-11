/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:36:25 by gusimone          #+#    #+#             */
/*   Updated: 2023/04/17 20:05:31 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	dup2_double(t_pip *p, int in, int out)
{
	if (dup2(in, 0) == -1)
	{
		parent_free(p);
		exit(1);
	}
	if (dup2(out, 1) == -1)
	{
		parent_free(p);
		exit(1);
	}
}

static	void	dup_in_first_dup(t_pip *p)
{
	if (p->outfile > 0)
		dup2_double(p, p->infile, p->outfile);
	else
	{
		if (p->nb_cmd == 1)
			dup2_double(p, p->infile, 1);
		else
			dup2_double(p, p->infile, p->pipe[2 * p->index + 1]);
	}
}

void	dup_first_cmd(t_pip *p)
{
	if (p->hd == 1)
	{	
		if (p->outfile > 0)
			dup2_double(p, p->fdhd[0], p->outfile);
		else
			dup2_double(p, p->fdhd[0], 1);
		return ;
	}
	if (p->infile > 0)
		dup_in_first_dup(p);
	else
	{
		if (p->outfile > 0)
			dup2_double(p, 0, p->outfile);
		else
		{
			if (p->nb_cmd == 1)
				dup2_double(p, 0, 1);
			else
				dup2_double(p, 0, p->pipe[2 * p->index + 1]);
		}
	}
}

void	dup_last_cmd(t_pip *p)
{
	if (p->hd == 1)
	{	
		if (p->outfile > 0)
			dup2_double(p, p->fdhd[0], p->outfile);
		else
			dup2_double(p, p->fdhd[0], 1);
		return ;
	}
	if (p->infile > 0)
	{
		if (p->outfile > 0)
			dup2_double(p, p->infile, p->outfile);
		else
			dup2_double(p, p->infile, 1);
	}
	else
	{
		if (p->outfile > 0)
			dup2_double(p, p->pipe[2 * p->index - 2], p->outfile);
		else
			dup2_double(p, p->pipe[2 * p->index - 2], 1);
	}
}

void	all_dup(t_pip *p)
{
	if (p->index == 0)
		dup_first_cmd(p);
	else if (p->index != (int)p->nb_cmd - 1)
	{
		if (p->infile > 0)
		{
			if (p->outfile > 0)
				dup2_double(p, p->infile, p->outfile);
			else
				dup2_double(p, p->pipe[2 * p->index - 2],
					p->pipe[2 * p->index + 1]);
		}
		else
		{
			if (p->outfile > 0)
				dup2_double(p, p->pipe[2 * p->index - 2], p->outfile);
			else
				dup2_double(p, p->pipe[2 * p->index - 2],
					p->pipe[2 * p->index + 1]);
		}
	}
	else
		dup_last_cmd(p);
}
