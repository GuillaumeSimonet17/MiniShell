/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:37:19 by gusimone          #+#    #+#             */
/*   Updated: 2023/03/28 14:22:24 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	is_contain(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	**lst_in_tab2(t_list *cmds)
{
	char	**cmd;
	int		a;
	t_list	*tmp;

	cmd = NULL;
	a = 0;
	tmp = cmds->content;
	if (tmp)
	{
		cmd = malloc(sizeof(char *)
				* (ft_lstsize(cmds) + (ft_lstsize(tmp) + 1)));
		if (!cmd)
			return (NULL);
		while (tmp && ((t_str *)(tmp->content))->type == 0)
		{
			cmd[a] = ((t_str *)(tmp->content))->str;
			tmp = tmp->next;
			a++;
		}
	}
	cmd[a] = 0;
	return (cmd);
}

char	**lst_in_tab(t_list *envp)
{
	char	**env;
	t_list	*envp_start;
	int		a;

	env = NULL;
	a = 0;
	if (envp)
	{
		envp_start = envp;
		env = malloc(sizeof(char *) * (ft_lstsize(envp) + 1));
		if (!env)
			return (NULL);
		while (a < ft_lstsize(envp_start))
		{
			env[a] = envp->content;
			envp = envp->next;
			a++;
		}
	}
	env[a] = 0;
	return (env);
}
