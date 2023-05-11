/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:36:49 by gusimone          #+#    #+#             */
/*   Updated: 2023/03/04 15:37:34 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	create_pipes(t_pip *p)
{
	size_t	i;

	i = 0;
	while (i < p->nb_cmd - 1)
	{
		if (pipe(p->pipe + 2 * i) < 0)
			parent_free(p);
		i++;
	}
}

void	close_pipes(t_pip *p)
{
	size_t	i;

	i = 0;
	while (i < (p->nb_pipe))
	{
		close(p->pipe[i]);
		i++;
	}
}
