/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:25:51 by marobert          #+#    #+#             */
/*   Updated: 2023/03/28 11:01:39 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "minishell.h"
# include "utils/utils.h"
# include "sigs.h"

# define SHLVL_TOO_HIGH "warning: shell level (%d) too high, resetting to 1\n"

#endif //MAIN_H
