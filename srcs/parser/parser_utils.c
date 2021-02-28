/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 11:43:00 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/09 22:29:04 by vanell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_tree_flag(t_tree *tree, t_flag *flag, char **cmd_l)
{
	tree->next = NULL;
	tree->target = NULL;
	tree->oper = NULL;
	flag->length = 0;
	flag->delim = 0;
	flag->err = -1;
	*cmd_l = NULL;
}

void	null_init_env(t_env **env)
{
	(*env)->key = NULL;
	(*env)->value = NULL;
	(*env)->next = NULL;
	(*env)->is_hidden = INVISIBLE;
	(*env)->eq = 0;
}

void	init_arg_red(t_input *input, int cnt)
{
	if (cnt > 0)
	{
		input->args = (char **)malloc(sizeof(char *) * (cnt + 1));
		input->args[cnt] = NULL;
	}
}

char	*join_line(char *str, char *str_pos,
					char *(ft_join)(const char *, const char *))
{
	char	*tmp;

	tmp = str;
	str = ft_join(str, str_pos);
	free(tmp);
	return (str);
}

void	cut_line(char **str, char *str_pos, char *(ft_dup)(const char *))
{
	char	*tmp;

	tmp = *str;
	*str = ft_dup(str_pos);
	clean_any_arr(tmp, NULL);
}
