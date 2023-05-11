/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:16:18 by marobert          #+#    #+#             */
/*   Updated: 2023/04/04 19:36:35 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sigs.h"

void	handler_heredoc(int sig)
{
	if (sig == SIGINT)
		exit(130);
}

void	init_heredoc_sig(struct sigaction *sa)
{
	struct termios	term;

	tcgetattr(0, &term);
	term.c_lflag &= (ICANON | ECHO);
	sigemptyset(&sa->sa_mask);
	sa->sa_handler = handler_heredoc;
	tcsetattr(0, TCSANOW, &term);
	sa->sa_flags = 0;
	sa->sa_restorer = NULL;
	sigaction(SIGINT, sa, NULL);
	sigaction(SIGQUIT, sa, NULL);
}
