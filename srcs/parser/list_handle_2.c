/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_handle_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 07:36:13 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/20 07:36:15 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	list_handle_2(t_tree *tree, t_env *env)
{
	char		*f_str;
	t_target	*cur;

	if (!tree)
		return ;
	cur = tree->target;
	while (cur)
	{
		f_str = NULL;
		if (!cur->type)
			space_handle(cur->val, &f_str, 0, env);
		else if (cur->type == DOUBLE_Q)
			db_quot_handle(cur->val, &f_str, 0, env);
		else if (cur->type == SINGLE_Q)
			sl_quot_handle(cur->val, &f_str);
		clean_any_arr(cur->val, NULL);
		cur->val = f_str;
		cur = cur->next;
	}
	list_handle_2(tree->next, env);
}
