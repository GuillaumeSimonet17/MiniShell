/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:17:50 by marobert          #+#    #+#             */
/*   Updated: 2023/04/17 19:20:53 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	add_lstnew_str_clean(t_list **lst, char *str)
{
	ft_lstadd_back(lst, ft_lstnew(new_str(clean_arg(str))));
}

static void	split_chev(const char *cmd, t_list **args, int *i, int *len)
{
	if (*len)
		add_lstnew_str_clean(args, ft_substr(cmd, *i - *len, *len));
	if (cmd[*i + 1] == cmd[*i])
		add_lstnew_str_clean(args, ft_substr(cmd, (*i)++, 2));
	else
		add_lstnew_str_clean(args, ft_substr(cmd, *i, 1));
	*len = 0;
}

static void	split_space(const char *cmd, int i, t_list **args, int *len)
{
	char	*tmp;
	int		expand;

	expand = 0;
	if (*len)
	{
		tmp = ft_substr(cmd, i - *len, *len);
		if (*args)
			expand = ((ft_strchr(tmp, '"') != 0) + \
					(ft_strchr(tmp, '\'') != 0)) * \
					(((t_str *)ft_lstlast(*args)->content)->type == CHEV_2L);
		add_lstnew_str_clean(args, tmp);
	}
	if (expand)
	{
		ft_memmove(((t_str *)ft_lstlast(*args)->content)->str + 1, \
			((t_str *)ft_lstlast(*args)->content)->str, \
			ft_strlen(((t_str *)ft_lstlast(*args)->content)->str));
		((char *)((t_str *)ft_lstlast(*args)->content)->str)[0] = '"';
	}
	*len = 0;
}

t_list	*smart_split(char *cmd)
{
	t_list	*args;
	char	mode;
	int		i;
	int		len;

	i = -1;
	len = 0;
	mode = SPACE;
	args = NULL;
	while (cmd[++i])
	{
		if (mode == SPACE && (cmd[i] == SINGLE || cmd[i] == DOUBLE))
			mode = cmd[i];
		else if (mode != SPACE && cmd[i] == mode)
			mode = SPACE;
		if (mode == SPACE && (cmd[i] == SPACE || cmd[i] == '\t'))
			split_space(cmd, i, &args, &len);
		else if (mode == SPACE && ft_strchr("<>", cmd[i]))
			split_chev(cmd, &args, &i, &len);
		else
			len++;
	}
	if (len)
		split_space(cmd, i, &args, &len);
	return (free(cmd), args);
}

t_list	*split_args(t_list *cmds)
{
	t_list	*start;

	start = cmds;
	while (cmds)
	{
		cmds->content = smart_split(cmds->content);
		cmds = cmds->next;
	}
	cmds = start;
	while (cmds)
	{
		if (cmds == start && !cmds->content)
			return (start);
		if (!cmds->content)
		{
			ft_dprintf(2, SYNTAX_ERROR_TOKEN, "|");
			g_err_code = 2;
			clear_cmds(&start);
			return (NULL);
		}
		cmds = cmds->next;
	}
	return (sort_args(start));
}
