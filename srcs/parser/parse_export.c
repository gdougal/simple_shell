/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 07:43:07 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/20 07:43:09 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	not_valid(t_input *input, int *i)
{
	while (input->args[*i] &&
			!ft_isalpha(input->args[*i][0]) && input->args[*i][0] != '_')
	{
		ft_putstr_fd("ПОЛУПОДПОДРУЧНЫЙ: export:", 1);
		ft_putstr_fd(input->args[*i], 1);
		ft_putstr_fd(" : not a valid identifier\n", 1);
		input->ret_code = 1;
		(*i)++;
	}
}

t_env		*parse_export(t_input *input, int i)
{
	int			j;
	t_env		*env_new;

	j = 0;
	if (!input->args || !input->args[i])
		return (NULL);
	not_valid(input, &i);
	env_new = malloc(sizeof(t_env));
	null_init_env(&env_new);
	if (input->args[i] && input->args[i][j])
	{
		env_new->key = ft_strdup_set(input->args[i], "=");
		j += ft_strlen(env_new->key);
		if (input->args[i][j] == '=')
		{
			env_new->eq = '=';
			j++;
		}
		if (input->args[i][j])
			env_new->value = ft_strdup(&input->args[i][j]);
		env_new->is_hidden = VISIBLE;
	}
	if (input->args[i] && input->args[++i])
		env_new->next = parse_export(input, i);
	return (env_new);
}
