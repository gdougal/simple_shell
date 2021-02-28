/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_handle_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 07:38:09 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/20 07:38:10 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	del_target(t_tree *tree)
{
	t_target	*tmp;
	t_target	*cur;

	cur = tree->target;
	while (cur)
	{
		tmp = cur->next;
		if (cur->val)
			free(cur->val);
		free(cur);
		cur = tmp;
	}
}

void		list_handle_3(t_tree *tree, char *f_str)
{
	t_target	*cur;

	if (!tree)
		return ;
	f_str = NULL;
	cur = tree->target;
	while (cur)
	{
		if (cur->val)
		{
			if (!f_str)
				f_str = ft_strdup(cur->val);
			else
				f_str = join_line(f_str, &cur->val[0], ft_strjoin);
		}
		cur = cur->next;
	}
	del_target(tree);
	tree->target = f_str;
	list_handle_3(tree->next, NULL);
}
