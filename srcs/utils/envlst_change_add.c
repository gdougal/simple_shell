/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlst_change_add.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:27:02 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/21 20:27:04 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstincase(t_env *env_prev, t_env *env_cur, t_env **target)
{
	char	*tmp;
	t_env	*tail;

	tmp = NULL;
	if (env_cur && *target)
	{
		tmp = env_cur->value;
		env_cur->value = ft_strdup((*target)->value);
		clean_any_arr(tmp, NULL);
		env_cur->eq = (*target)->eq;
		env_cur->is_hidden = (*target)->is_hidden;
		*target = (*target)->next;
	}
	else if (*target)
	{
		tail = malloc(sizeof(t_env));
		null_init_env(&tail);
		tail->key = ft_strdup((*target)->key);
		tail->value = ft_strdup((*target)->value);
		tail->eq = (*target)->eq;
		tail->is_hidden = (*target)->is_hidden;
		env_prev->next = tail;
		*target = (*target)->next;
	}
}
