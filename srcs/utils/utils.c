/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:04:19 by gusimone          #+#    #+#             */
/*   Updated: 2023/04/02 18:21:43 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"

void	*clear_cmds(t_list **cmds)
{
	t_list	*tmp;

	tmp = *cmds;
	while (tmp)
	{
		ft_lstclear((t_list **)&(tmp->content), free_t_str);
		tmp = tmp->next;
	}
	ft_lstclear(cmds, free);
	return (*cmds);
}

int	get_syntax_error(const t_list *tmp, const t_list *start)
{
	return ((ft_strchr("<>|", ((t_str *)tmp->content)->str[0]) && \
			(tmp->before && \
			ft_strchr("<>|", ((t_str *)tmp->before->content)->str[0]))) || \
			(((t_str *)tmp->content)->str[0] == '|' && \
			(tmp == start || !tmp->next)));
}

int	is_var_name_valid(char *cmd, char *var, int max)
{
	int	i;

	if (!(ft_isalpha(var[0]) || var[0] == '_'))
	{
		ft_dprintf(2, "%s: '%s': %s\n", cmd, var, INVALID_ID);
		g_err_code = 1;
		return (0);
	}
	i = 0;
	while (var[i] && i < max)
	{
		if (!(ft_isalnum(var[i]) || var[i] == '_') && \
		!(!ft_strncmp(cmd, "export", -1) && !ft_strncmp(var + i, "+=", 2)))
		{
			ft_dprintf(2, "%s: '%s': %s\n", cmd, var, INVALID_ID);
			g_err_code = 1;
			return (0);
		}
		i++;
	}
	return (1);
}

void	*useless(void *content)
{
	return (content);
}

size_t	get_nb_occ(char *str, char c)
{
	size_t	i;
	size_t	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] == c)
			nb++;
		i++;
	}
	return (nb);
}
