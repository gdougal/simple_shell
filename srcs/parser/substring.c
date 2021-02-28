/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substring.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 07:15:20 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/20 07:15:22 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	skip_q(const char *tmp, int *i)
{
	int	t;

	while (tmp[*i])
	{
		if ((t = is_set(tmp[*i], "'\"", 0))
			&& tmp[*i - 1] != '\\' && t == tmp[*i + 1])
			*i += 2;
		else
			break ;
	}
}

static void	if_body(const char *tmp, int *i, int *start, t_target *cur)
{
	*i = *i + 1;
	*start = *i;
	while (tmp[*i])
	{
		if ((tmp[*i] == DOUBLE_Q && tmp[*i - 1] != '\\' &&
			cur->type == DOUBLE_Q) || (tmp[*i] == SINGLE_Q
								&& cur->type == SINGLE_Q))
			break ;
		(*i)++;
	}
}

static void	else_body(const char *tmp, int *i)
{
	while (tmp[*i])
	{
		(*i)++;
		if ((is_set(tmp[*i], "'\"/", 0) && tmp[*i - 1] != '\\'))
			break ;
	}
}

static void	calculate(const char *tmp, int *i, t_target *cur, int *start)
{
	skip_q(tmp, i);
	*start = *i;
	cur->type = is_set(tmp[*i], "\"'", 0);
	while (tmp[*i])
	{
		if (cur->type && (*i == 0 || tmp[*i - 1] != '\\'))
			if_body(tmp, i, start, cur);
		else
			else_body(tmp, i);
		break ;
	}
}

void		subsub_lst_mk(const char *tmp, t_target *arglst, int i, int k)
{
	t_target	*cur;
	int			start;

	if (!tmp || !tmp[i])
		return ;
	cur = arglst;
	if (i)
	{
		cur->next = malloc(sizeof(t_tree));
		cur = cur->next;
		cur->val = NULL;
	}
	cur->next = NULL;
	calculate(tmp, &i, cur, &start);
	if (i == start)
		return ;
	cur->val = ft_calloc((i - start + 1), sizeof(char));
	ft_memcpy(cur->val, &tmp[start], (i - start));
	if ((cur->type == SINGLE_Q || cur->type == DOUBLE_Q)
	&& is_set(tmp[i], &cur->type, 0))
		i++;
	subsub_lst_mk(tmp, cur, i, k);
}
