/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:35:30 by marobert          #+#    #+#             */
/*   Updated: 2023/03/13 11:12:11 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	remove_var(char *var, t_list **envp)
{
	t_list	*tmp;

	tmp = *envp;
	while (tmp)
	{
		if (!ft_strncmp(var, tmp->content, ft_strlen(var)) \
			&& (((char *)tmp->content)[ft_strlen(var)] == '=' || \
			((char *)tmp->content)[ft_strlen(var)] == 0))
		{
			if (!tmp->before)
			{
				*envp = tmp->next;
				ft_lstdelone(tmp->before, free);
				tmp->before = NULL;
			}
			else
			{
				tmp->before->next = tmp->next;
				if (tmp->next)
					tmp->next->before = tmp->before;
				return (ft_lstdelone(tmp, free));
			}
		}
		tmp = tmp->next;
	}
}

int	unset(t_list *argv, t_list **envp)
{
	g_err_code = 0;
	argv = argv->next;
	while (argv)
	{
		remove_var(((t_str *)argv->content)->str, envp);
		argv = argv->next;
	}
	return (1);
}
