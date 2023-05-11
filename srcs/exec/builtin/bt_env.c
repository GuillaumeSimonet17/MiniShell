/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:31:15 by marobert          #+#    #+#             */
/*   Updated: 2023/03/24 13:46:35 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	env(t_list *envp, t_pip *p)
{
	while (envp)
	{
		if (ft_strchr(envp->content, '='))
		{
			if (p->nb_cmd > 1)
			{
				ft_putstr_fd((char *)envp->content, p->pipe[2 * p->index + 1]);
				ft_putstr_fd("\n", p->pipe[2 * p->index + 1]);
			}
			else
				printf("%s\n", (char *)envp->content);
		}
		envp = envp->next;
	}
	g_err_code = 0;
	return (1);
}
