/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 09:49:23 by marobert          #+#    #+#             */
/*   Updated: 2023/02/07 14:56:55 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/tab_utils.h"

/*
 * Free a tab of string then the tab itself
 * @param tab The tab to free
 */
void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

/*
 * Append a new element to an exising tab
 * Malloc its current size + 1 for the new element
 * Copy every element's pointer and append the new one
 * If new_elem is empty, it free it and return the original tab
 * Free the old tab
 * @param tab The tab to append to
 * @param new_elem The new element to append
 * @return The new tab or NULL if malloc failed
 */
char	**append_tab(char **tab, char *new_elem)
{
	int		i;
	char	**new_tab;

	if (new_elem && new_elem[0] == 0)
		return (free(new_elem), tab);
	i = 0;
	while (tab[i])
		i++;
	new_tab = malloc(sizeof(char *) * (i + 3));
	if (!new_tab)
		return (0);
	i = 0;
	while (tab[i])
	{
		new_tab[i] = tab[i];
		i++;
	}
	new_tab[i] = new_elem;
	new_tab[i + 1] = NULL;
	free(tab);
	return (new_tab);
}

int	tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
