/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_finder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:49:43 by gdougal           #+#    #+#             */
/*   Updated: 2020/11/26 11:49:45 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*lst_finder_simple(char *str, t_env *lst_env)
{
	t_env	*tmp;
	int		k;
	char	*ret_0;

	tmp = lst_env;
	ret_0 = NULL;
	while (tmp && !ret_0)
	{
		k = ft_strcmp(tmp->key, str);
		if (k == 0)
		{
			if ((tmp->is_hidden == VISIBLE || !ft_strcmp(tmp->key, "?"))
			&& tmp->value)
				return (tmp->value);
		}
		tmp = tmp->next;
	}
	if (ft_isdigit(*str) && str[1])
		return (&str[1]);
	if (!ret_0)
		return ("");
	return (ret_0);
}
