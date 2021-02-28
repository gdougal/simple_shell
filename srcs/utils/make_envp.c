/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:06:23 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/21 20:06:24 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env		*make_envp(char **envp_arg)
{
	char	**tmp;
	t_env	*head;
	t_env	*cur_list;
	int		i;

	i = 0;
	if (!(cur_list = malloc(sizeof(t_env))))
		return (NULL);
	head = cur_list;
	while (envp_arg[i])
	{
		if (i != 0)
		{
			cur_list->next = malloc(sizeof(t_env));
			cur_list = cur_list->next;
		}
		tmp = ft_split(envp_arg[i], '=');
		cur_list->key = tmp[0];
		cur_list->eq = '=';
		cur_list->value = tmp[1];
		cur_list->is_hidden = VISIBLE;
		free(tmp);
		i++;
	}
	return (head);
}
