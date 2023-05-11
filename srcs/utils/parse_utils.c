/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:03:06 by marobert          #+#    #+#             */
/*   Updated: 2023/04/18 11:23:14 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	are_cmds_valid(t_list *cmds)
{
	while (cmds)
	{
		if (((t_str *)cmds->content)->type != STR)
		{
			if (!cmds->next)
			{
				ft_dprintf(2, "%s\n", SYNTAX_ERROR);
				return (0);
			}
			cmds = cmds->next;
			if (!cmds || ((t_str *) cmds->content)->type != STR)
			{
				ft_dprintf(2, "%s near unexpected token `%s`\n", SYNTAX_ERROR, \
						((t_str *)cmds->content)->str);
				return (0);
			}
		}
		cmds = cmds->next;
	}
	return (1);
}

/**
 * Change the mode depending of the current mode and the current char in command
 * @param cmd current char in command line
 * @param mode pointer to the mode SPACE|SINGLE|DOUBLE
 * @return 0 if the mode changed, 1 if it didn't
 */
int	get_mode(const char cmd, char *mode)
{
	if (*mode != SPACE && cmd == *mode)
	{
		*mode = SPACE;
		return (0);
	}
	else if (*mode == SPACE && (cmd == DOUBLE || cmd == SINGLE))
	{
		*mode = cmd;
		return (0);
	}
	return (1);
}

char	*clean_arg(char *cmd)
{
	int		i;
	char	mode;

	i = 0;
	mode = SPACE;
	while (cmd[i])
	{
		if (mode == SPACE && (cmd[i] == DOUBLE || cmd[i] == SINGLE))
		{
			mode = cmd[i];
			ft_memmove(cmd + i, cmd + i + 1, ft_strlen(cmd + i));
			cmd[ft_strlen(cmd)] = 0;
		}
		else if (mode != SPACE && cmd[i] == mode)
		{
			ft_memmove(cmd + i, cmd + i + 1, ft_strlen(cmd + i));
			cmd[ft_strlen(cmd)] = 0;
			mode = SPACE;
		}
		else
			i++;
	}
	cmd[ft_strlen(cmd)] = 0;
	return (cmd);
}

int	get_var_len(char *cmd, size_t i)
{
	int	len;

	i++;
	if (cmd[i] == '?' || cmd[i] == '"' || cmd[i] == '\'')
		return (2);
	if (ft_isdigit(cmd[i]))
		return (2);
	len = 1;
	while (ft_isalnum(cmd[i]) || cmd[i] == '_')
	{
		i++;
		len++;
	}
	return (len);
}

char	*replace_all_vars(char *str, t_list *env)
{
	size_t	i;
	int		var_len;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			var_len = get_var_len(str, i);
			if (var_len)
				cmd_replace(env, &str, &i, SPACE);
		}
		i++;
	}
	return (str);
}
