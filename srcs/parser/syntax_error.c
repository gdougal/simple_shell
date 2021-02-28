/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 07:14:06 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/20 07:14:09 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int		pre(char *line, int *i, t_flag *flag, char *ost_line)
{
	while (is_set(line[*i], " ", 0))
		(*i)++;
	if ((!ost_line && flag->delim) || !line[*i])
	{
		ft_putstr_fd("Syntax error\n", 1);
		return (0);
	}
	return (1);
}

static	void	empty_skip_and_quote_status(char *line, int *i, int *k)
{
	int		j;

	j = 0;
	while (line[*i])
	{
		if ((j = is_set(line[*i], "'\"", 0))
			&& line[*i - 1] != '\\' && j == line[*i + 1])
			(*i) += 2;
		else
			break ;
	}
	if (is_set(line[*i], "'\"", 0) && line[*i - 1] != '\\')
	{
		if (*k && *k == is_set(line[*i], "'\"", 0))
			*k = 0;
		else if (!(*k))
			*k = (int)line[*i];
	}
}

static int		red_checker(char *line, int *i, int k)
{
	int		red;

	if (!k && (red = is_set(line[*i], "><", 0)) && line[*i - 1] != '\\')
	{
		while (is_set(line[++(*i)], "><", 0))
			red += line[*i];
		if (!line[*i] || ((red % REDIR_IN > 0 || red > 2 * REDIR_IN)
			&& (red % REDIR_OUT > 0 || red > REDIR_OUT)))
		{
			ft_putstr_fd("Syntax error\n", 1);
			return (0);
		}
	}
	return (1);
}

static int		tail_check_q(int k)
{
	if (k)
	{
		ft_putstr_fd("Syntax error quote\n", 1);
		return (0);
	}
	return (1);
}

int				syntax_error(char *line, char *ost_line, t_flag *flag)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (!pre(line, &i, flag, ost_line))
		return (0);
	while (line[i])
	{
		empty_skip_and_quote_status(line, &i, &k);
		if (!red_checker(line, &i, k))
			return (0);
		if (!k && line[i] && is_set(line[i], "(){}[]", 0)
				&& line[i - 1] != '\\')
		{
			ft_putstr_fd("Syntax error\n", 1);
			return (0);
		}
		i++;
	}
	if (!tail_check_q(k))
		return (0);
	return (1);
}
