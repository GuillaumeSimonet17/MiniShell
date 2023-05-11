/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:34:12 by marobert          #+#    #+#             */
/*   Updated: 2023/04/17 20:04:55 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"

void	handle_inception(t_list *cmds, struct sigaction *sa)
{
	char	*cmd;

	cmd = ((t_str *)((t_list *)cmds->content)->content)->str;
	if ((size_t)(ft_strnstr(cmd, "/minishell", -1) - cmd) == \
						ft_strlen(cmd) - 10)
	{
		sigemptyset(&sa->sa_mask);
		sa->sa_flags = SA_RESTART;
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
}
