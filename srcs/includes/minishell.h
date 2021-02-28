/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:50:55 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/25 21:40:55 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MINISHELL_H
# define _MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/uio.h>
# include <signal.h>
# include <dirent.h>
# include "parser.h"
# include "../gnl/get_next_line.h"

int g_sig_c;

typedef struct	s_norme_1
{
	char		**path;
	char		*tmp;
	int			i;
	int			k;
	struct stat	stat1;
}				t_norme_1;

typedef struct	s_norme_0
{
	int			fd_rd;
	int			fd_wt;
	int			p_fd[2];
	int			pid;
	int			status;
	t_input		input;
	char		*line;
	t_env		lst_env;
	int			pip;
}				t_norme_0;

void			null_init_env(t_env **env);
t_env			*make_envp(char **envp_arg);
void			init_env(t_env *lst_env, int status);
void			chng_status(t_env *lst_env, int status, t_input *input);
void			signal_ctrl_slash(void);
void			signal_ctrl_c(void);
void			ft_echo(t_input *input, t_env *env);
void			ft_env(t_input *input, t_env *env);
void			ft_export(t_input *input, t_env *env);
void			ft_pwd(t_input *input, t_env *env);
void			ft_cd(t_input *input, t_env *env);
void			ft_unset(t_input *input, t_env *env);
void			ft_execve(t_input *input, t_env *env);
void			lst_cpy(t_env **duplicate, t_env *env);
int				ft_envsize(t_env *lst);
void			del_lst_env(t_env **env);
void			ft_lstincase(t_env *env_prev, t_env *env_cur, t_env **target);
void			bubble_sort_lists(t_env *sorted);
void			cmd_not_found(t_input *input, t_env *lst_env);
void			arg_req(t_input *input, t_env *lst_env);
void			is_a_dir(t_input *input, t_env *lst_env);
void			ft_exit(t_input *input, t_env *env);
void			free_input(t_input *input);

#endif
