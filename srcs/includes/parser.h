/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanell <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:50:57 by vanell            #+#    #+#             */
/*   Updated: 2020/12/21 19:06:11 by vanell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PARSER_H
# define _PARSER_H

# include "libft.h"

# define SINGLE_Q	39
# define DOUBLE_Q	34
# define REDIR_IN	62
# define REDIR_OUT	60
# define PIPE		124
# define STDIN 0
# define VISIBLE 1
# define INVISIBLE 0

struct s_input;

struct s_env;

typedef void			(*t_command_function)(struct s_input*, struct s_env*);

typedef struct			s_flag
{
	int					length;
	char				delim;
	int					err;
}						t_flag;

typedef struct			s_target
{
	char				*val;
	char				type;
	struct s_target		*next;
}						t_target;

typedef struct			s_env
{
	char				*key;
	char				eq;
	char				*value;
	int					is_hidden;
	struct s_env		*next;
}						t_env;

typedef struct			s_input
{
	t_command_function	cmd_func;
	char				*cmd;
	char				**args;
	t_env				*env_new;
	int					fd_fclos;
	int					pipe;
	int					ret_code;
}						t_input;

typedef struct			s_tree
{
	void				*target;
	char				*oper;
	struct s_tree		*next;
}						t_tree;

void					parser(char **line, t_env *list_env, t_input *input);
void					init_tree_flag(t_tree *tree, t_flag *flag,
						char **cmd_l);
int						syntax_error(char *line, char *ost_line, t_flag *flag);
int						length_cmds(char *line, t_flag *flag);
void					list_carg(const char *cmd_l, t_tree *tree, int i);
void					list_handle_1(t_tree *tree, int *cnt);
void					subsub_lst_mk(const char *tmp,
						t_target *arglst, int i, int k);
void					list_handle_2(t_tree *tree, t_env *env);
void					sl_quot_handle(char *targ, char **f_str);
void					db_quot_handle(char *targ, char **f_str,
						int i, t_env *env);
void					space_handle(char *targ, char **f_str,
						int i, t_env *env);
void					list_handle_3(t_tree *tree, char *f_str);
void					parse_redirections(char *key_value,
						t_input *input, char *name);
void					init_arg_red(t_input *input, int cnt);
void					list_handle_4(t_tree *tree, t_input *input,
						int cnt, int r_cnt);
void					command_handler(t_input *input);
void					execve_handler(t_input *input, t_env *env);
void					redir_handler(t_tree *tree, t_input *input);
t_env					*parse_export(t_input *input, int i);
void					input_init(t_input *input);
void					cut_line(char **str, char *str_pos,
						char *(ft_dup)(const char *));
char					*join_line(char *str, char *str_pos,
						char *(ft_join)(const char *, const char *));
char					*lst_finder_simple(char *str, t_env *lst_env);

#endif
