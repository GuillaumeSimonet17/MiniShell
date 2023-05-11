/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:51:07 by marobert          #+#    #+#             */
/*   Updated: 2023/03/28 20:18:48 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_list	*push_back_2(t_list *cmds, t_list *to_move)
{
	t_list	*start;

	start = cmds;
	if (!to_move->next->next)
		return (start);
	while (cmds && cmds != to_move)
		cmds = cmds->next;
	if (cmds == to_move)
	{
		if (to_move == start)
			start = to_move->next->next;
		else
		{
			to_move->before->next = to_move->next->next;
			to_move->before->next->before = to_move->before;
		}
		to_move->next->next = NULL;
		ft_lstadd_back(&start, to_move);
	}
	return (start);
}

static int	is_list_end(t_list *start, int print)
{
	while (start)
	{
		if (((t_str *)start->content)->type != STR)
		{
			if (start->next && ((t_str *)start->next->content)->type == STR)
				start = start->next->next;
			else
			{
				if (print)
					ft_dprintf(2, SYNTAX_ERROR_NEWLINE);
				return (-1);
			}
		}
		else
			return (0);
	}
	return (1);
}

static void	push_io(t_list **sub, t_list **sub_start, enum e_type type)
{
	t_list	*first;

	first = NULL;
	while ((*sub && !is_list_end(*sub, 0)) || first != *sub)
	{
		if (((t_str *)(*sub)->content)->type % 2 == type % 2 && \
			((t_str *)(*sub)->content)->type != STR)
		{
			if (!first)
				first = *sub;
			*sub_start = push_back_2((*sub_start), *sub);
			*sub = *sub_start;
		}
		else
			*sub = (*sub)->next;
	}
}

static int	is_sorted(t_list *cmds)
{
	while (cmds)
	{
		if (((t_str *)cmds->content)->type != STR)
		{
			if (is_list_end(cmds, 0))
				return (1);
			return (0);
		}
		cmds = cmds->next;
	}
	return (0);
}

t_list	*sort_args(t_list *cmds)
{
	t_list	*start;
	t_list	*sub;
	t_list	*sub_start;

	start = cmds;
	while (cmds)
	{
		sub_start = cmds->content;
		if (!is_sorted(sub_start))
		{
			sub = sub_start;
			push_io(&sub, &sub_start, CHEV_L);
			sub = sub_start;
			push_io(&sub, &sub_start, CHEV_R);
			if (is_list_end(sub, 1) == -1)
				return (clear_cmds(&start));
		}
		if (!are_cmds_valid(sub_start))
			return (clear_cmds(&start));
		cmds->content = sub_start;
		cmds = cmds->next;
	}
	return (start);
}
