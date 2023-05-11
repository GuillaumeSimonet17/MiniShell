/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_str.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:53:22 by marobert          #+#    #+#             */
/*   Updated: 2023/02/28 10:27:35 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_STR_H
# define T_STR_H

# include <stdlib.h>

# include "libft.h"

typedef enum e_type {
	STR = 0,
	CHEV_L = 1,
	CHEV_R = 2,
	CHEV_2L = 3,
	CHEV_2R = 4,
}	t_type;

typedef struct s_str {
	char	*str;
	t_type	type;
}	t_str;

t_str	*new_str(char *content);
void	free_t_str(void *elem);

#endif //T_STR_H
