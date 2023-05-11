/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:08:31 by gusimone          #+#    #+#             */
/*   Updated: 2023/04/15 16:33:08 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	is_here_doc(t_pip *p, t_list *cmds, t_list *tmp)
{
	int	i;

	i = 0;
	p->hd = 0;
	tmp = cmds->content;
	while (tmp)
	{
		if (((t_str *)(tmp->content))->type == 3)
			p->hd = 1;
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	check_tab(char **end, char *word)
{
	int	a;

	a = 0;
	while (end[a])
	{
		if (ft_strncmp(word, end[a], ft_strlen(end[tab_len(end) - 1])) == 0)
			return (1);
		a++;
	}
	return (0);
}

// void	get_tab_limits(t_pip *p, t_list *cmds, int i)
// {
// 	t_list	*tmp;
// 	int		a;

// 	a = 0;
// 	tmp = cmds->content;
// 	p->end = ft_free_malloc(p->m_free, (sizeof(char *) * (i + 1)));
// 	while (i > 0)
// 	{
// 		if (((t_str *)(tmp->content))->type == 3)
// 			p->end[a++] = ((t_str *)(tmp->next->content))->str;
// 		tmp = tmp->next;
// 		i--;
// 	}
// 	p->end[a] = 0;
// }

// int	first_limit(t_pip *p, char *wd)
// {
// 	if (ft_strncmp(wd, p->end[tab_len(p->end) - 1],
// 			ft_strlen(wd)) == 0)
// 	{
// 		if (ft_isprint(p->end[0][0]) && ft_strncmp(wd, p->end[0],
// 			ft_strlen(p->end[0])) == 0)
// 			return (1);
// 		else if (ft_isprint(p->end[0][0]) == 0 && !wd[0])
// 			return (1);
// 	}
// 	return (0);
// }

// char	*join_to_print(t_pip *p, char *wd, char *to_print)
// {
// 	int	i;
// 	int	a;
// 	int	size;

// 	a = 0;
// 	i = -1;
// 	size = ft_strlen(wd) + ft_strlen(to_print) + 2;
// 	if (p->end_ln == 1)
// 		size += 1;
// 	p->s = ft_free_malloc(p->m_free, size);
// 	while (to_print[++i])
// 		p->s[i] = to_print[i];
// 	while (wd[a])
// 		p->s[i++] = wd[a++];
// 	if (p->end_ln == 1)
// 		p->s[i++] = '$';
// 	p->s[i++] = '\n';
// 	p->s[i] = 0;
// 	return (p->s);
// }
