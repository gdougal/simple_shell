/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 07:46:12 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/25 22:15:22 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	redir_handler(t_tree *tree, t_input *input)
{
	if (!tree)
		return ;
	if (tree->oper && tree->target)
		parse_redirections(tree->oper, input, tree->target);
	redir_handler(tree->next, input);
}
