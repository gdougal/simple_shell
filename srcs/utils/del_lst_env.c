/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_lst_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:25:40 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/21 20:25:42 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_lst_env(t_env **env)
{
	t_env	*tmp;
	t_env	*cur;

	cur = *env;
	while (cur)
	{
		if (cur->key)
			free(cur->key);
		if (cur->value)
			free(cur->value);
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
}
