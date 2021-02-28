/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_arglist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 07:09:40 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/20 07:09:48 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	space_skip(const char *cmd_l, int *i)
{
	int		j;

	j = 0;
	while (cmd_l[*i] == ' ')
		(*i)++;
	while (cmd_l[*i])
	{
		if ((j = is_set(cmd_l[*i], "'\"", 0))
			&& cmd_l[*i - 1] != '\\' && j == cmd_l[*i + 1])
			(*i) += 2;
		else
			break ;
	}
}

static int	body(const char *cmd_l, int *k, int *i)
{
	if (cmd_l[*i] == '\\')
		*i += 1;
	if (is_set(cmd_l[*i], "'\"", 0) && cmd_l[*i - 1] != '\\')
	{
		if (*k && *k == is_set(cmd_l[*i], "'\"", 0))
			*k = 0;
		else if (!(*k))
			*k = (int)cmd_l[*i];
	}
	if (!(*k) && is_set(cmd_l[*i], "><", 0))
		if (!is_set(cmd_l[++(*i)], "><", 0) && cmd_l[*i - 2] != '\\')
			return (1);
	if (!(*k) && cmd_l[*i] == ' ' && cmd_l[*i - 1] != '\\')
		return (1);
	if (!(*k) && cmd_l[*i] == '\\' && cmd_l[*i - 1] == '\\')
	{
		*k = '\\';
		return (1);
	}
	return (0);
}

static void	get_name(const char *cmd_l, int *i, char **name)
{
	int		start;
	int		k;

	k = 0;
	space_skip(cmd_l, i);
	start = *i;
	while (cmd_l[(*i)])
	{
		if (body(cmd_l, &k, i))
			break ;
		(*i)++;
	}
	if (*i == start)
		return ;
	*name = ft_calloc((*i - start + 1), sizeof(char));
	ft_memcpy(*name, (char *)&cmd_l[start], (*i - start));
	if (k == '\\')
		*i += 1;
}

void		list_carg(const char *cmd_l, t_tree *tree, int i)
{
	char	*name;

	space_skip(cmd_l, &i);
	if (!cmd_l || !cmd_l[i])
		return ;
	else
		get_name(cmd_l, &i, &name);
	if (tree->target)
	{
		tree->next = malloc(sizeof(t_tree));
		tree = tree->next;
		tree->next = NULL;
	}
	if (name && is_set(name[0], "><", 0))
	{
		tree->oper = name;
		get_name(cmd_l, &(i), &name);
		tree->target = name;
	}
	else
	{
		tree->target = name;
		tree->oper = NULL;
	}
	list_carg(cmd_l, tree, i);
}
