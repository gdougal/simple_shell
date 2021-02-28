/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 04:15:06 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/20 04:15:09 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	post_cmd_handle(t_input *input, t_flag *flag,
							t_tree *tree, t_env *list_env)
{
	if (input->cmd_func == ft_execve)
		execve_handler(input, list_env);
	else if (input->cmd_func == ft_export)
		input->env_new = parse_export(input, 1);
	if (input->cmd_func != cmd_not_found)
		redir_handler(tree, input);
	input->pipe = (int)flag->delim;
}

static void	fr_line(char **line)
{
	free(*line);
	*line = NULL;
}

static int	line_chnger(char **line, char **cmd_l, t_flag *flag)
{
	length_cmds(*line, flag);
	if (!flag->length)
	{
		flag->err = 258;
		if (**line != '\0')
			ft_putstr_fd("Syntax error\n", 1);
		fr_line(line);
		return (1);
	}
	*cmd_l = ft_calloc((flag->length + 1), sizeof(char));
	ft_memcpy(*cmd_l, *line, flag->length);
	if ((*line)[flag->length] && (*line)[flag->length + 1])
		cut_line(line, &((*line)[flag->length + 1]), ft_strdup);
	else
		fr_line(line);
	if (!syntax_error(*cmd_l, *line, flag))
	{
		flag->err = 258;
		fr_line(cmd_l);
		fr_line(line);
		return (1);
	}
	return (0);
}

static void	tree_cleaner(t_tree *tree)
{
	t_tree *cur;

	clean_any_arr(tree->target, NULL);
	clean_any_arr(tree->oper, NULL);
	tree = tree->next;
	while (tree)
	{
		clean_any_arr(tree->target, NULL);
		clean_any_arr(tree->oper, NULL);
		cur = tree->next;
		free(tree);
		tree = cur;
	}
}

void		parser(char **line, t_env *list_env, t_input *input)
{
	t_tree	tree;
	t_flag	flag;
	char	*cmd_l;
	int		cnt;

	cnt = 0;
	init_tree_flag(&tree, &flag, &cmd_l);
	input_init(input);
	if (line_chnger(line, &cmd_l, &flag))
	{
		input->ret_code = flag.err;
		return ;
	}
	list_carg(cmd_l, &tree, 0);
	list_handle_1(&tree, &cnt);
	list_handle_2(&tree, list_env);
	list_handle_3(&tree, NULL);
	init_arg_red(input, cnt);
	list_handle_4(&tree, input, 0, 0);
	command_handler(input);
	post_cmd_handle(input, &flag, &tree, list_env);
	tree_cleaner(&tree);
	clean_any_arr(cmd_l, NULL);
}
