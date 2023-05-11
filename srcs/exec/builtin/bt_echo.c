/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:54:00 by gusimone          #+#    #+#             */
/*   Updated: 2023/04/17 17:44:22 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include <errno.h>

int	only_n(char *s)
{
	int	i;

	i = 1;
	while (s[i])
	{
		if (s[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	echo_wn(t_list *tmp)
{
	if (tmp->next->next)
	{
		while (ft_strncmp(((t_str *)(tmp->next->content))->str, "-n", 2) == 0)
		{
			if (only_n(((t_str *)(tmp->next->content))->str) == 0)
				break ;
			else
				tmp = tmp->next;
		}
		tmp = tmp->next;
		while (tmp->next && ((t_str *)(tmp->content))->type == 0)
		{
			printf("%s", ((t_str *)(tmp->content))->str);
			tmp = tmp->next;
			if (((t_str *)(tmp->content))->type == 0)
				printf(" ");
		}
		if (((t_str *)(tmp->content))->type == 0)
			printf("%s", ((t_str *)(tmp->content))->str);
	}
	else
		exit (1);
}

void	echo_wtn(t_list *tmp)
{
	tmp = tmp->next;
	while (tmp->next && ((t_str *)(tmp->content))->type == 0)
	{
		printf("%s", ((t_str *)(tmp->content))->str);
		tmp = tmp->next;
		printf(" ");
	}
	if (((t_str *)(tmp->content))->type == 0)
		printf("%s", ((t_str *)(tmp->content))->str);
	printf("\n");
}

int	echo(t_list *cmds, t_pip *p)
{
	g_err_code = 0;
	p->pid = fork();
	if (p->pid == -1)
		return (errno);
	if (p->pid == 0)
	{
		all_dup(p);
		close_pipes(p);
		if (!cmds->next)
		{
			printf("\n");
			exit (1);
		}
		if (cmds->next
			&& ft_strncmp(((t_str *)(cmds->next->content))->str, "-n", 2) == 0
					&& ((t_str *)(cmds->next->content))->str
				[ft_strlen(((t_str *)(cmds->next->content))->str) - 1] == 'n')
			echo_wn(cmds);
		else
			echo_wtn(cmds);
		exit(0);
	}
	return (0);
}
