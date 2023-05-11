/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:48:07 by marobert          #+#    #+#             */
/*   Updated: 2023/04/04 14:52:59 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sigs.h"

static void	handle_sigint(int re_display, int show)
{
	g_err_code = 130;
	if (show)
		write(1, "^C", 2);
	write(1, "\n", 1);
	rl_replace_line("", 0);
	if (re_display)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

static void	handle_sigquit(void)
{
	g_err_code = 131;
	printf("Quit (core dumped)\n");
	rl_replace_line("", 0);
}

void	handler_def(int sig)
{
	if (sig == SIGINT)
		handle_sigint(1, 1);
}

void	handler_cmd(int sig)
{
	if (sig == SIGINT)
		handle_sigint(0, 0);
	else if (sig == SIGQUIT)
		handle_sigquit();
}
