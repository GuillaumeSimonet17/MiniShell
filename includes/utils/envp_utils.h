/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:40:52 by marobert          #+#    #+#             */
/*   Updated: 2023/01/30 13:41:20 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVP_UTILS_H
# define ENVP_UTILS_H

# include <stdlib.h>

# include "libft.h"
# include "minishell.h"

char	*get_env_value(char *var, t_list *envp);

#endif //ENVP_UTILS_H
