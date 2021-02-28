/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_handle_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 07:17:37 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/20 07:17:39 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		list_handle_1(t_tree *tree, int *cnt)
{
	t_target	*arglst;
	char		*tmp;

	tmp = NULL;
	if (!tree)
		return ;
	tmp = (char *)tree->target;
	arglst = malloc(sizeof(t_target));
	subsub_lst_mk(tmp, arglst, 0, 0);
	if (tree->target)
		free(tree->target);
	tree->target = arglst;
	if (!tree->oper && tree->target)
		(*cnt)++;
	list_handle_1(tree->next, cnt);
}
