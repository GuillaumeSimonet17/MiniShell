/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:23:01 by marobert          #+#    #+#             */
/*   Updated: 2023/04/05 10:38:52 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <termios.h>

# include "libft.h"
# include "utils/t_str.h"
# include "exec.h"

# ifdef COLOR
#  define PROMPT "\e[38;5;45mshell ─▶\e[0m "
# endif

# ifndef COLOR
#  define COLOR
#  define PROMPT "mshell ─▶ "
# endif

/*
 * 1 Liste chainé pour envp
 * 1 Liste chainée de liste chainée pour les args des commandes entre les pipes
 */

/// On launch, increase SH_LEVEL, create it if necessary then in a loop
/// execute get_args and execute exec_cmd or multi_pipes
/// \return
//int		main(int argc, char **argv, char **envp);

///
/// \param	argv list of command arguments
/// 		(including options and the command itself)
/// \return	error code on error, 0 if no error
// int		echo(t_list *cmds, t_pip *p);

///
/// \param	envp environment variables
/// \return	error code on error, 0 else
// int		pwd(t_pip *p);

/// Execute readline and parse it
/// \param	envp environment variables
/// \return list of parsed args which can be freed
t_list	*get_args(t_list *envp);

///
/// \param	argv list of command arguments
/// \param	envp environment variables
/// \return	error code on error, 0 else
int		cd(t_list *argv, t_list **envp);

///
/// \param	argv list of command arguments
/// \return	error code on error, 0 else
int		bt_exit(t_list *argv);

///
/// \param	argv list of command arguments
/// \param	envp environment variables
/// \return	error code on error, 0 else
//int		export(t_list *argv, t_list **envp, t_pip *p);

///
/// \param	argv list of command arguments
/// \param	envp environment variables
/// \return	error code on error, 0 else
int		unset(t_list *argv, t_list **envp);

/// Execute each command from cmds with exec_cmd
/// \param	cmds list of list of command arguments
/// \param	envp environment variables
/// \return	error code on error, 0 else
//int		multi_pipes(t_list *cmds, t_list **envp);

///
/// \param	envp environment variables
/// \return	error code on error, 0 else
//int		env(t_list *envp, t_pip *p);

/// read user input until encounter delimiter
/// \param	delimiter heredoc delimiter
/// \return	the final string without delimiter
char	*heredoc(char *delimiter);

///
/// \param	args list of command arguments
/// \param	envp environment variables
/// \return	error code on error, 0 else
//int		exec_cmd(t_list *args, t_list **envp);

typedef struct s_global
{
	struct termios	print_attr;
	struct termios	hide_attr;
}	t_global;

extern int	g_err_code;

#endif //MINISHELL_H