/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:26:36 by marobert          #+#    #+#             */
/*   Updated: 2023/04/20 15:51:35 by marobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	g_err_code;

static char	*increase_shlvl(char *str)
{
	char	*final;
	int		final_len;
	int		sh_lvl;
	char	*tmp;

	sh_lvl = ft_atoi(str + 6) + 1;
	if (sh_lvl < 1)
		sh_lvl = 0;
	else if (sh_lvl >= 1000)
	{
		ft_dprintf(2, SHLVL_TOO_HIGH, sh_lvl);
		sh_lvl = 1;
	}
	final_len = (int)ft_intlen(sh_lvl) + 7;
	final = malloc(sizeof(char) * final_len);
	if (!final)
		return (NULL);
	final[0] = 0;
	ft_strlcat(final, "SHLVL=", final_len);
	tmp = ft_itoa(sh_lvl);
	if (!tmp)
		return (free(final), NULL);
	ft_strlcat(final, tmp, final_len);
	free(tmp);
	return (final);
}

static t_list	*new_env(void)
{
	t_list	*env;
	char	path[PATH_MAX];
	char	*tmp;

	env = ft_lstnew("OLDPWD");
	getcwd(path, PATH_MAX);
	tmp = ft_calloc(ft_strlen(path) + 5, sizeof(char));
	if (!tmp)
		return (NULL);
	ft_strlcat(tmp, "PWD=", ft_strlen(path) + 5);
	ft_strlcat(tmp, path, ft_strlen(path) + 5);
	ft_lstadd_back(&env, ft_lstnew(tmp));
	ft_lstadd_back(&env, ft_lstnew(ft_strdup("SHLVL=1")));
	return (env);
}

static t_list	*start(char	**envp)
{
	t_list	*env;
	int		i;
	int		sh_lvl;

	g_err_code = 0;
	if (!envp || !*envp)
		return (new_env());
	else
	{
		sh_lvl = 0;
		env = ft_lstnew(ft_strdup(envp[0]));
		i = 1;
		while (envp[i])
		{
			if (ft_strncmp(envp[i], "SHLVL=", 6))
				ft_lstadd_back(&env, ft_lstnew(ft_strdup(envp[i])));
			else if (++sh_lvl)
				ft_lstadd_back(&env, ft_lstnew(increase_shlvl(envp[i])));
			i++;
		}
		if (!sh_lvl)
			ft_lstadd_back(&env, ft_lstnew(ft_strdup("SHLVL=1")));
	}
	return (env);
}

static void	handle_ctrl_d(struct sigaction *sa, t_global *shell)
{
	init_sigactions(sa, 1, shell);
	bt_exit(NULL);
}

int	main(int ac, char **av, char **envp)
{
	t_list				*env;
	t_list				*cmds;
	struct sigaction	sa;
	t_global			shell;

	(void) ac;
	(void) av;
	env = start(envp);
	init_shell_attr(&shell);
	while (42)
	{
		init_sigactions(&sa, 0, &shell);
		cmds = get_args(env);
		if (cmds == (t_list *)-1)
			handle_ctrl_d(&sa, &shell);
		if (cmds && cmds->content)
		{
			init_sigactions(&sa, 1, &shell);
			multi_pipes(cmds, &env, &sa);
			clear_cmds(&cmds);
		}
		else
			free(cmds);
	}
	ft_lstclear(&env, free);
}
