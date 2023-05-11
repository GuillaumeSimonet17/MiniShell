/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:12:55 by gusimone          #+#    #+#             */
/*   Updated: 2023/04/17 20:15:09 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <readline/readline.h>

# include "libft.h"
# include "builtins.h"
# include "minishell.h"
# include "utils/t_str.h"
# include "utils/utils.h"
# include "utils/envp_utils.h"
# include "utils/tab_utils.h"

typedef struct s_pip
{
	int			*pipe;
	char		**cmd_paths;
	char		**cmd_args;
	char		*cmd;
	char		**cmd_tab;
	char		***cmd_tab_tab;
	char		*env_path;
	int			infile;
	int			outfile;
	int			pid;
	int			index;
	char		*infile_name;
	char		*outfile_name;
	int			err_infile;
	int			err_outfile;
	int			got_outfile;
	int			got_infile;
	int			no_create_out;
	int			hd;
	int			fdhd[2];
	int			tmp_fd;
	char		*end;
	char		*s;
	char		*s2;
	char		*n;
	char		*n2;
	int			nb;
	char		*line;
	int			exp;
	size_t		nb_cmd;
	size_t		nb_pipe;
	t_m_free	*m_free;
}	t_pip;

// builtin
int		echo(t_list *cmds, t_pip *p);
int		env(t_list *envp, t_pip *p);
int		export(t_list *argv, t_list **envp, t_pip *p);
int		pwd(t_pip *p);

// exec_cmd
int		exec_cmd(t_list *cmds, t_list **envp, t_pip *p);
void	get_hd(t_list *cmds, t_pip *p, int i);

// multi_pipes.c
int		multi_pipes(t_list *cmds, t_list **env, struct sigaction *sa);
void	child_process(t_pip *p, t_list *cmds, t_list *envp, \
			struct sigaction *sa);
void	get_cmd_path(t_pip *p);
void	multi_cmds(t_pip *p, t_list *cmds, t_list **env, struct sigaction *sa);
void	simple_cmd(t_pip *p, t_list *cmds, t_list **env, struct sigaction *sa);
void	process(t_pip *p, t_list *cmds, t_list **env, struct sigaction *sa);

//dup.c
void	dup2_double(t_pip *p, int in, int out);
void	dup_first_cmd(t_pip *p);
void	dup_last_cmd(t_pip *p);
void	all_dup(t_pip *p);

// pipes.c
void	create_pipes(t_pip *p);
void	close_pipes(t_pip *p);

// files.c
int		get_infile_outfile(t_list *cmds, t_pip *p);
void	init_and_close_files(t_pip *p);

// cmds.c
int		get_nb_cmds(t_list *cmds);
char	*get_cmd(char **path, char *cmd);

// utils_exec.c
int		is_contain(char *s, char c);
char	**lst_in_tab2(t_list *cmds);
char	**lst_in_tab(t_list *cmds);

//free_exec.c
void	parent_free(t_pip *p);
void	ft_free_child(t_pip *p);
void	free_pipe(t_pip *p);

//check_err.c
int		cmd_error(char *s);
void	check_error(t_pip *p);
void	check_err_infile(t_pip *p);

//here_doc.c
void	here_doc(t_pip *p, t_list *cmds, t_list *env);
void	hd_one_cmd(t_pip *p, t_list *cmds, t_list *env);
void	init_heredoc_sig(struct sigaction *sa);

//utils_hd.c
int		is_here_doc(t_pip *p, t_list *cmds, t_list *tmp);
int		check_tab(char **end, char *word);
void	get_tab_limits(t_pip *p, t_list *cmds, int i);
int		first_limit(t_pip *p, char *wd);
char	*join_to_print(t_pip *p, char *wd, char *to_print);

//exec_utils
void	handle_inception(t_list *cmds, struct sigaction *sa);

#endif