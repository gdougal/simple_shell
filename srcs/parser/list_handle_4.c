/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_handle_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 07:40:53 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/20 07:40:55 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	list_handle_4(t_tree *tree, t_input *input, int cnt, int r_cnt)
{
	if (!tree)
		return ;
	if (!tree->oper && !input->cmd)
		input->cmd = ft_strdup(tree->target);
	if (!tree->oper)
		input->args[cnt++] = ft_strdup(tree->target);
	list_handle_4(tree->next, input, cnt, r_cnt);
}
