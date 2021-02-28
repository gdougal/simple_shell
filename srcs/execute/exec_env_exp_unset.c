/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env_exp_unset.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:14:51 by gdougal           #+#    #+#             */
/*   Updated: 2020/11/17 12:25:50 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	put_var(t_env *cur, int flag, t_input *input)
{
	if ((cur->is_hidden == VISIBLE && input->cmd_func == ft_export) ||
		(cur->is_hidden == VISIBLE && input->cmd_func == ft_env && cur->value))
	{
		if (!flag)
			ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(cur->key, 1);
		if (cur->eq)
			write(1, "=\"", 2);
		ft_putstr_fd(cur->value, 1);
		if (cur->eq)
			write(1, "\"", 1);
		write(1, "\n", 1);
	}
}

void		ft_env(t_input *input, t_env *env)
{
	t_env	*duplicate;
	t_env	*cur;
	int		flag;

	lst_cpy(&duplicate, env);
	flag = ft_strcmp(input->cmd, "export");
	if (!flag)
		bubble_sort_lists(duplicate);
	cur = duplicate;
	while (cur)
	{
		put_var(cur, flag, input);
		cur = cur->next;
	}
	del_lst_env(&duplicate);
}

static void	export_add_body(t_env *target, t_env *env)
{
	t_env	*env_cur;
	t_env	*env_prev;
	int		flag;

	flag = 0;
	while (target && target->key)
	{
		env_cur = env;
		while (env_cur)
		{
			flag = 0;
			if (!ft_strcmp(env_cur->key, target->key))
			{
				ft_lstincase(env_prev, env_cur, &target);
				flag = 1;
				break ;
			}
			env_prev = env_cur;
			env_cur = env_cur->next;
		}
		if (!flag)
			ft_lstincase(env_prev, env_cur, &target);
	}
}

void		ft_export(t_input *input, t_env *env)
{
	t_env	*target;

	target = input->env_new;
	if (target)
	{
		export_add_body(target, env);
		del_lst_env(&input->env_new);
	}
	else
		ft_env(input, env);
}

void		ft_unset(t_input *input, t_env *env)
{
	t_env	*cur;
	int		i;

	i = 1;
	while (input->args[i])
	{
		cur = env;
		while (cur)
		{
			if (!ft_strcmp(cur->key, input->args[i]))
			{
				cur->is_hidden = INVISIBLE;
				break ;
			}
			cur = cur->next;
		}
		i++;
	}
}
