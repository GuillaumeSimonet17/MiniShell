/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:50:25 by marobert          #+#    #+#             */
/*   Updated: 2023/04/17 19:22:32 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sigs.h"

void	init_shell_attr(t_global *shell)
{
	tcgetattr(STDIN_FILENO, &shell->print_attr);
	tcgetattr(STDIN_FILENO, &shell->hide_attr);
	shell->hide_attr.c_lflag &= (ICANON | ECHO);
}

void	init_sigactions(struct sigaction *sa, int cmd, t_global *shell)
{
	sigemptyset(&sa->sa_mask);
	if (cmd)
	{
		sa->sa_handler = handler_cmd;
		tcsetattr(STDIN_FILENO, TCSANOW, &shell->print_attr);
	}
	else
	{
		sa->sa_handler = handler_def;
		tcsetattr(STDIN_FILENO, TCSANOW, &shell->hide_attr);
	}
	sa->sa_flags = 0;
	sa->sa_restorer = NULL;
	sigaction(SIGINT, sa, NULL);
	sigaction(SIGQUIT, sa, NULL);
}
