/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:47:59 by marobert          #+#    #+#             */
/*   Updated: 2023/04/17 19:22:44 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGS_H
# define SIGS_H

# include <signal.h>
# include <termios.h>

# include "minishell.h"
# include "parsing.h"

void	init_shell_attr(t_global *shell);
void	init_sigactions(struct sigaction *sa, int cmd, t_global *shell);

void	handler_def(int sig);
void	handler_cmd(int sig);

#endif //SIGS_H
