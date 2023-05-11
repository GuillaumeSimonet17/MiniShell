/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:39:07 by marobert          #+#    #+#             */
/*   Updated: 2023/04/20 16:15:13 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	change_pwd(t_list **env, char *new_pwd)
{
	t_list	*tmp;

	if (!new_pwd)
		return (ft_dprintf(2, ERROR_WD));
	tmp = *env;
	while (tmp)
	{
		if (ft_strnstr(tmp->content, "PWD=", 4))
		{
			free(tmp->content);
			tmp->content = ft_calloc(sizeof(char), PATH_MAX + 7);
			if (!tmp->content)
				return (ft_dprintf(2, "malloc err\n"));
			ft_strlcat(tmp->content, "PWD=", PATH_MAX + 7);
			ft_strlcat(tmp->content, new_pwd, PATH_MAX + 7);
			return (1);
		}
		tmp = tmp->next;
	}
	ft_lstadd_back(env, ft_lstnew(ft_calloc(sizeof(char), PATH_MAX + 7)));
	ft_strlcat(ft_lstlast(*env)->content, "PWD=", PATH_MAX + 7);
	ft_strlcat(ft_lstlast(*env)->content, new_pwd, PATH_MAX + 7);
	return (2);
}

int	change_old_pwd(t_list **env, char *new_old)
{
	t_list	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (!new_old)
			return (remove_var("OLDPWD", env), 1);
		if (!ft_strncmp(tmp->content, "OLDPWD=", 7))
		{
			free(tmp->content);
			tmp->content = ft_calloc(sizeof(char), PATH_MAX + 8);
			if (!tmp->content)
				return (ft_dprintf(2, "malloc err\n"));
			ft_strlcat(tmp->content, "OLDPWD=", PATH_MAX + 8);
			ft_strlcat(tmp->content, new_old, PATH_MAX + 8);
			return (1);
		}
		tmp = tmp->next;
	}
	ft_lstadd_back(env, ft_lstnew(ft_calloc(sizeof(char), PATH_MAX + 8)));
	ft_strlcat(ft_lstlast(*env)->content, "OLDPWD=", PATH_MAX + 8);
	ft_strlcat(ft_lstlast(*env)->content, new_old, PATH_MAX + 8);
	return (2);
}

static int	cd_old(char *old, t_list **env, char *cwd)
{
	if (old)
	{
		change_old_pwd(env, get_env_value("PWD", *env));
		if (chdir(old))
		{
			ft_dprintf(2, "cd: %s: %s\n", old, NO_FILE_DIR);
			change_old_pwd(env, old);
		}
		else
			printf("%s\n", old);
		change_pwd(env, getcwd(cwd, PATH_MAX));
		return (free(old), 0);
	}
	g_err_code = 1;
	return (ft_dprintf(2, "cd: OLDPWD %s\n", NOT_SET));
}

int	cd_args(const t_list *cmd, char *old, t_list **env)
{
	char	cwd[PATH_MAX];

	if (!ft_strncmp(((t_str *)cmd->content)->str, "-", -1))
		return (cd_old(old, env, cwd));
	change_old_pwd(env, get_env_value("PWD", *env));
	if (ft_strchr(((t_str *)cmd->content)->str, '~'))
		((t_str *)cmd->content)->str = replace_var(((t_str *)cmd->content) \
		->str, "~", get_env_value("HOME", *env), 0);
	if (chdir(((t_str *)cmd->content)->str))
	{
		change_old_pwd(env, old);
		ft_dprintf(2, "cd: %s %s\n", ((t_str *)cmd->content)->str, NO_FILE_DIR);
		g_err_code = 1;
	}
	change_pwd(env, getcwd(cwd, PATH_MAX));
	return (free(old), 0);
}

int	cd(t_list *cmd, t_list **env)
{
	char	*old;
	char	cwd[PATH_MAX];

	g_err_code = 0;
	old = get_env_value("OLDPWD", *env);
	if (old)
		old = ft_strdup(get_env_value("OLDPWD", *env));
	cmd = cmd->next;
	if (cmd && ((t_str *)cmd->content)->type == STR)
		return (cd_args(cmd, old, env));
	free(old);
	if (!get_env_value("HOME", *env))
		return (ft_dprintf(2, "cd: HOME %s\n", NOT_SET));
	change_old_pwd(env, get_env_value("PWD", *env));
	chdir(get_env_value("HOME", *env));
	change_pwd(env, getcwd(cwd, PATH_MAX));
	return (1);
}
