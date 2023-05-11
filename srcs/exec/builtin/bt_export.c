/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:29:46 by marobert          #+#    #+#             */
/*   Updated: 2023/04/20 15:42:29 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	print_var(char *var, t_pip *p)
{
	char	*var_name;

	if (!ft_strchr(var, '='))
	{
		if (p->nb_cmd > 1)
			ft_dprintf(p->pipe[2 * p->index + 1], "declare -x %s\n", var);
		else
			ft_printf("declare -x %s\n", var);
		return ;
	}
	var_name = ft_substr(var, 0, ft_strchr(var, '=') - var);
	if (!var_name)
		return ;
	if (p->nb_cmd > 1)
		ft_dprintf(p->pipe[2 * p->index + 1], "declare -x %s=\"%s\"\n", \
				var_name, ft_strchr(var, '=') + 1);
	else
		ft_printf("declare -x %s=\"%s\"\n", var_name, ft_strchr(var, '=') + 1);
	free(var_name);
}

static void	set_var(char *var, int var_len, t_list *envp)
{
	char	*old;
	char	*new;
	size_t	new_len;

	old = envp->content;
	if (var[var_len] == '+')
	{
		new_len = ft_strlen(envp->content) + ft_strlen(var + var_len + 2) + 2;
		new = ft_calloc(new_len, sizeof(char));
		if (!new)
			return ;
		ft_strlcat(new, envp->content, new_len);
		if (!ft_strchr(envp->content, '='))
			ft_strlcat(new, "=", new_len);
		ft_strlcat(new, var + var_len + 2, new_len);
		envp->content = new;
	}
	else
		envp->content = ft_strdup(var);
	free(old);
}

static char	*remove_plus(char *str)
{
	size_t	plus_pos;

	plus_pos = ft_strchr(str, '+') - str;
	ft_memmove(str + plus_pos, str + plus_pos + 1, ft_strlen(str + plus_pos));
	str[ft_strlen(str)] = 0;
	return (str);
}

static void	add_var(char *var, t_list **envp_start)
{
	t_list	*envp;
	int		var_len;

	envp = *envp_start;
	var_len = (int)ft_strlen(var);
	if (ft_strchr(var, '='))
		var_len = (int)(ft_strchr(var, '=') - (char *)var);
	if (ft_strnstr(var, "=", -1) == ft_strnstr(var, "+=", -1) + 1)
		var_len--;
	if (!is_var_name_valid("export", var, var_len))
		return ;
	while (envp)
	{
		if (!ft_strncmp(var, envp->content, var_len))
		{
			if (var[var_len] == '=' || var[var_len] == '+')
				return (set_var(var, var_len, envp));
			else if (var[var_len] == 0)
				return ;
		}
		envp = envp->next;
	}
	ft_lstadd_back(envp_start, ft_lstnew(ft_strdup(remove_plus(var))));
}

int	export(t_list *argv, t_list **envp, t_pip *p)
{
	t_list	*dup;
	t_list	*tmp;

	g_err_code = 0;
	if (!argv->next)
	{
		dup = sort_lst(ft_lstmap(*envp, useless, free));
		while (dup)
		{
			tmp = dup;
			dup = dup->next;
			print_var(tmp->content, p);
			free(tmp);
		}
		return (1);
	}
	argv = argv->next;
	while (argv && ((t_str *)argv->content)->type == STR)
	{
		add_var(((t_str *)argv->content)->str, envp);
		argv = argv->next;
	}
	return (1);
}
