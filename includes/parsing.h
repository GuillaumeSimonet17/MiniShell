/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:49:47 by marobert          #+#    #+#             */
/*   Updated: 2023/04/17 17:43:40 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "minishell.h"
# include "utils/envp_utils.h"
# include "utils/utils.h"
# include "utils/tab_utils.h"
# include "utils/lst_utils.h"

# define SPACE ' '
# define SINGLE '\''
# define DOUBLE '"'

# define SPACE ' '
# define SINGLE '\''
# define DOUBLE '"'
# define SYNTAX_ERROR "syntax error "
# define SYNTAX_ERROR_NEWLINE "syntax error near unexpected token `newline`\n"
# define SYNTAX_ERROR_TOKEN "syntax error near unexpected token `%s`\n"

t_list	*smart_expand_cmds(t_list *cmds, t_list *envp);
char	*smart_expand_cmd(char *cmd, t_list *envp);
char	*replace_var(char *str, char *find, char *replace, size_t start);
void	cmd_replace(t_list *envp, char **cmd, size_t *i, char mode);

t_list	*split_args(t_list *cmds);

t_list	*sort_args(t_list *cmds);

int		are_cmds_valid(t_list *cmds);
int		get_mode(char cmd, char *mode);
char	*clean_arg(char *cmd);
int		get_var_len(char *cmd, size_t i);
char	*replace_all_vars(char *str, t_list *env);

#endif //PARSING_H
