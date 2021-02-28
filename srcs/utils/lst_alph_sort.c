/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_alph_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:31:04 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/21 20:31:06 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	swap(t_env *a, t_env *b)
{
	t_env temp;

	temp.key = a->key;
	temp.value = a->value;
	temp.eq = a->eq;
	temp.is_hidden = a->is_hidden;
	a->key = b->key;
	a->value = b->value;
	a->eq = b->eq;
	a->is_hidden = b->is_hidden;
	b->key = temp.key;
	b->value = temp.value;
	b->eq = temp.eq;
	b->is_hidden = temp.is_hidden;
}

void		bubble_sort_lists(t_env *sorted)
{
	int		swapped;
	t_env	*cur_lst;
	t_env	*last_lst;

	last_lst = NULL;
	while (1)
	{
		swapped = 0;
		cur_lst = sorted;
		while (cur_lst->next != last_lst)
		{
			if (ft_strcmp(cur_lst->key, cur_lst->next->key) > 0)
			{
				swap(cur_lst, cur_lst->next);
				swapped = 1;
			}
			cur_lst = cur_lst->next;
		}
		last_lst = cur_lst;
		if (!swapped)
			break ;
	}
}
