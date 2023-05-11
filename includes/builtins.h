/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:39:02 by marobert          #+#    #+#             */
/*   Updated: 2023/04/17 16:24:29 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <string.h>

# include "libft.h"
# include "minishell.h"
# include "utils/envp_utils.h"
# include "utils/lst_utils.h"

# include "exec.h"

# define NO_FILE_DIR "no such file or directory"
# define TOO_MANY_ARGS "too many arguments"
# define NUM_ARG_REQ "numeric argument required"
# define NOT_SET "not set"
# define ERROR_WD "problem with working directory\n"

void	remove_var(char *var, t_list **envp);

#endif //BUILTINS_H
