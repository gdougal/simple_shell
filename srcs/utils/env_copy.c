/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:38:33 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/22 15:38:34 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lst_cpy(t_env **duplicate, t_env *env)
{
	t_env	*cur_env;
	t_env	*cur_dup;

	*duplicate = malloc(sizeof(t_env));
	cur_env = env;
	cur_dup = *duplicate;
	null_init_env(&cur_dup);
	while (cur_env)
	{
		cur_dup->key = ft_strdup(cur_env->key);
		cur_dup->value = ft_strdup(cur_env->value);
		cur_dup->is_hidden = cur_env->is_hidden;
		cur_dup->eq = cur_env->eq;
		if (cur_env->next)
		{
			cur_dup->next = malloc(sizeof(t_env));
			cur_dup = cur_dup->next;
			null_init_env(&cur_dup);
		}
		else
			cur_dup->next = NULL;
		cur_env = cur_env->next;
	}
}
