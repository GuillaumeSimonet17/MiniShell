/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:32:09 by marobert          #+#    #+#             */
/*   Updated: 2023/03/13 11:08:01 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

# include "minishell.h"

# define INVALID_ID "not a valid identifier"

size_t	ft_intlen(int nb);
void	*clear_cmds(t_list **cmds);
int		get_syntax_error(const t_list *tmp, const t_list *start);
int		is_var_name_valid(char *cmd, char *var, int max);
void	*useless(void *content);
size_t	get_nb_occ(char *str, char c);

#endif //UTILS_H
