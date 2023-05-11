/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:41:04 by marobert          #+#    #+#             */
/*   Updated: 2023/03/30 10:31:40 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/envp_utils.h"

/*
 * Search the value of a variable in envp
 * if he variable does not exist, return NULL
 * else, return its value
 * @param var the name of the variable to search
 * @param envp the environment variables
 * @return the value of the variable or NULL
 */
char	*get_env_value(char *var, t_list *envp)
{
	if (!var || !envp)
		return (NULL);
	if (!*var)
		return (ft_strdup("$"));
	if (!ft_strncmp(var, "?", -1))
		return (ft_itoa(g_err_code));
	while (envp)
	{
		if (!ft_strncmp(var, envp->content, ft_strlen(var)) \
			&& ((char *)envp->content)[ft_strlen(var)] == '=')
			return (ft_strnstr(envp->content, "=", -1) + 1);
		envp = envp->next;
	}
	return (NULL);
}
