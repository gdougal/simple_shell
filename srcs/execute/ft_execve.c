/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:28:36 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/25 22:13:44 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**env_lst_to_arr(t_env *env)
{
	char	**env_arr;
	char	*tmp;
	t_env	*cur_lst;
	int		lst_count;

	cur_lst = env;
	lst_count = ft_envsize(env);
	errno = 0;
	env_arr = (char**)malloc(sizeof(char*) * lst_count + 1);
	env_arr[lst_count] = NULL;
	lst_count = 0;
	while (cur_lst)
	{
		if (cur_lst->is_hidden == VISIBLE)
		{
			tmp = ft_strjoin(cur_lst->key, "=");
			tmp = join_with_free(tmp, cur_lst->value);
			env_arr[lst_count++] = tmp;
		}
		cur_lst = cur_lst->next;
	}
	return (env_arr);
}

void		ft_execve(t_input *input, t_env *env)
{
	char	**env_arr;

	env_arr = env_lst_to_arr(env->next);
	errno = 0;
	execve(input->cmd, input->args, env_arr);
	input->ret_code = errno;
	if (errno)
		strerror(errno);
}
