/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:23:41 by marobert          #+#    #+#             */
/*   Updated: 2023/04/18 13:40:40 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	mode_space(char *input, t_list **lst, char **start, char *mode)
{
	if (*input == '\'' || *input == '"')
		*mode = *input;
	else if (*input == '|' && input++)
	{
		ft_lstadd_back(lst, \
			ft_lstnew(\
				ft_substr(*start, 0, input - *start - 1)));
		*start = input;
	}
}

static t_list	*split_pipes(char *input)
{
	t_list	*lst;
	char	*start;
	char	mode;

	lst = NULL;
	start = input;
	mode = SPACE;
	while (*input)
	{
		if (mode == SPACE)
			mode_space(input, &lst, &start, &mode);
		else if (*input == mode)
			mode = SPACE;
		input++;
	}
	if (!*input && !*start && lst)
	{
		ft_lstclear(&lst, free);
		ft_dprintf(2, SYNTAX_ERROR_NEWLINE);
		return (NULL);
	}
	ft_lstadd_back(&lst, ft_lstnew(ft_substr(start, 0, input - start)));
	return (lst);
}

t_list	*get_args(t_list *envp)
{
	t_list	*cmds;
	char	*input;

	input = readline(PROMPT);
	if (!input)
		return ((t_list *)-1);
	if (input[0])
		add_history(input);
	if (get_nb_occ(input, ' ') + get_nb_occ(input, '|') + \
		get_nb_occ(input, '\t') == ft_strlen(input) && get_nb_occ(input, '|'))
	{
		g_err_code = 2;
		ft_dprintf(2, SYNTAX_ERROR_TOKEN, "|");
		free(input);
		return (NULL);
	}
	cmds = split_pipes(input);
	free(input);
	if (!cmds)
		return (NULL);
	return (smart_expand_cmds(cmds, envp));
}
