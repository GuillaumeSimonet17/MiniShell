/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 09:48:51 by marobert          #+#    #+#             */
/*   Updated: 2023/01/28 10:10:39 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAB_UTILS_H
# define TAB_UTILS_H

# include <stdlib.h>

# include "libft.h"
# include "parsing.h"

void	free_tab(char **tab);
char	**append_tab(char **tab, char *new_elem);
int		tab_len(char **tab);

#endif //TAB_UTILS_H
