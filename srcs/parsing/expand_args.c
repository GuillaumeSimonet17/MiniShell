/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:58:44 by marobert          #+#    #+#             */
/*   Updated: 2023/04/20 16:48:26 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*replace_var(char *str, char *find, char *replace, size_t start)
{
	size_t	final_len;
	char	*final;
	long	var_loc;

	final_len = ft_strlen(str) - ft_strlen(find) + 1;
	var_loc = ft_strnstr(str + start, find, -1) - str;
	if (replace)
		final_len += ft_strlen(replace);
	final = ft_calloc(final_len, sizeof(char));
	if (!final)
		return (NULL);
	ft_strlcat(final, str, var_loc + 1);
	if (replace)
		ft_strlcat(final, replace, final_len);
	ft_strlcat(final, str + var_loc + ft_strlen(find), \
				final_len);
	if (!ft_strncmp(find, "$?", -1))
		free(replace);
	free(str);
	return (final);
}

static char	*get_quoted(char *str)
{
	char	*quoted;
	char	quote[2];
	size_t	i;
	size_t	j;

	if (!str)
		return (NULL);
	quote[0] = SINGLE;
	quote[1] = DOUBLE;
	quoted = ft_calloc(ft_strlen(str) + 1 + (get_nb_occ(str, quote[\
				ft_strchr(str, SINGLE) == 0]) * 2), sizeof(char));
	if (!quoted)
		return (NULL);
	i = 0;
	j = -1;
	while (str[++j])
	{
		if (str[j] == quote[ft_strchr(str, SINGLE) == 0])
			quoted[i++] = quote[ft_strchr(str, SINGLE) != 0];
		quoted[i] = str[j];
		if (str[j] == quote[ft_strchr(str, SINGLE) == 0])
			quoted[++i] = quote[ft_strchr(str, SINGLE) != 0];
		i++;
	}
	return (quoted);
}

void	cmd_replace(t_list *envp, char **cmd, size_t *i, char mode)
{
	char	*var_name;
	char	*var_val;
	char	*var_val_quoted;
	size_t	to_add;

	var_name = ft_substr((*cmd), (*i), get_var_len((*cmd), *i));
	var_val = get_env_value(var_name + 1, envp);
	var_val_quoted = get_quoted(var_val);
	to_add = ft_strlen(var_val) - 1;
	if (var_val && (ft_strchr(var_val, '\'') || ft_strchr(var_val, '"')) \
		&& mode == SPACE)
	{
		*cmd = replace_var((*cmd), var_name, var_val_quoted, *i);
		if (!ft_strncmp(var_name, "$?", -1))
			free(var_val);
	}
	else if (!ft_strncmp(var_name, "$'", 2) && mode == DOUBLE)
		*i += 2;
	else
		*cmd = replace_var((*cmd), var_name, var_val, *i);
	*i += to_add;
	free(var_val_quoted);
	free(var_name);
}

char	*smart_expand_cmd(char *cmd, t_list *envp)
{
	size_t	i;
	char	mode;
	int		hd;

	i = -1;
	hd = 0;
	mode = SPACE;
	while (cmd[++i])
	{
		if (ft_strchr(" \t", cmd[i]))
			hd = 0;
		if (cmd[i] == '<' && mode == SPACE && i > 0 && cmd[i - 1] != '<')
			hd = 1;
		else if (cmd[i] == '<' && mode == SPACE)
			hd++;
		if (hd == 2 && cmd[i] == '<' && ++i)
			while (ft_strchr(" \t", cmd[i]))
				i++;
		if (get_mode(cmd[i], &mode))
			if ((mode == SPACE || mode == DOUBLE) && cmd[i] == '$')
				if (get_var_len(cmd, i) && hd != 2)
					cmd_replace(envp, &cmd, &i, mode);
	}
	return (cmd);
}

t_list	*smart_expand_cmds(t_list *cmds, t_list *envp)
{
	t_list	*start;

	start = cmds;
	while (cmds)
	{
		cmds->content = smart_expand_cmd(cmds->content, envp);
		cmds = cmds->next;
	}
	return (split_args(start));
}
