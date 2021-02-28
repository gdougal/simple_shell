/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_vario_handle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 07:19:27 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/25 22:48:40 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	env_part_space(char *targ, char **p_str, int *i, t_env *env)
{
	char *tmp;

	tmp = ft_strdup_set(&targ[++(*i)], "\\$'");
	(*i) += ft_strlen(tmp);
	*p_str = ft_strdup(lst_finder_simple(tmp, env));
	free(tmp);
}

void		space_handle(char *targ, char **f_str, int i, t_env *env)
{
	char	*p_str;

	p_str = NULL;
	if (!targ || !targ[i])
		return ;
	if (targ[i] == '$' && (i == 0 || targ[i - 1] != '\\')
			&& ft_strlen(targ) > 1)
		env_part_space(targ, &p_str, &i, env);
	else if (targ[i] == '\\' && targ[i - 1] != '\\')
		i++;
	else
	{
		p_str = ft_strdup_set(&targ[i], "\\$");
		i += ft_strlen(p_str);
	}
	if (!(*f_str) && p_str)
		*f_str = ft_strdup(p_str);
	else if (p_str)
		*f_str = join_line(*f_str, p_str, &ft_strjoin);
	if (p_str)
		clean_any_arr(p_str, NULL);
	space_handle(targ, f_str, i, env);
}

static void	env_part_quote(char *targ, char **p_str, int *i, t_env *env)
{
	char *tmp;

	tmp = ft_strdup_set(&targ[++(*i)], "\\$ '");
	*i += ft_strlen(tmp);
	*p_str = ft_strdup(lst_finder_simple(tmp, env));
	free(tmp);
}

void		db_quot_handle(char *targ, char **f_str, int i, t_env *env)
{
	char	*p_str;

	p_str = NULL;
	if (!targ || !targ[i])
		return ;
	if (targ[i] == '$' && (i == 0 || targ[i - 1] != '\\')
								&& ft_strlen(targ) > 1)
		env_part_quote(targ, &p_str, &i, env);
	else if (targ[i] == '\\' && targ[i - 1] != '\\')
		i++;
	else
	{
		p_str = ft_strdup_set(&targ[i], "\\$");
		i += ft_strlen(p_str);
	}
	if (!(*f_str) && p_str)
		*f_str = ft_strdup(p_str);
	else if (p_str)
		*f_str = join_line(*f_str, p_str, &ft_strjoin);
	if (p_str)
		free(p_str);
	db_quot_handle(targ, f_str, i, env);
}

void		sl_quot_handle(char *targ, char **f_str)
{
	*f_str = ft_strdup(targ);
}
