/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 07:44:44 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/20 07:44:45 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	part_2(t_norme_1 *norm, t_input *input)
{
	if (!norm->k && norm->stat1.st_mode & X_OK)
	{
		clean_any_arr(input->cmd, NULL);
		input->cmd = ft_strdup(norm->tmp);
	}
	if (norm->k && !ft_strcmp(input->cmd, "."))
		input->cmd_func = arg_req;
	else if (norm->k && (!ft_strcmp(input->cmd, "./")
	|| !ft_strncmp(input->cmd, "/", 1)))
		input->cmd_func = is_a_dir;
	else if (norm->k)
		input->cmd_func = cmd_not_found;
	clean_any_arr(norm->tmp, norm->path);
}

static void	norm_init_1(t_norme_1 *norm)
{
	norm->path = NULL;
	norm->tmp = NULL;
	norm->k = 1;
	norm->i = 0;
}

void		execve_handler(t_input *input, t_env *env)
{
	t_norme_1	norm;

	norm_init_1(&norm);
	norm.path = ft_split(lst_finder_simple("PATH", env), ':');
	if (input->cmd && input->cmd[0] != '/' && input->cmd[0] != '.')
	{
		while (norm.path[norm.i] && norm.k != 0)
		{
			clean_any_arr(norm.tmp, NULL);
			norm.tmp = ft_strjoin(norm.path[norm.i], "/");
			norm.tmp = join_with_free(norm.tmp, input->cmd);
			norm.k = stat(norm.tmp, &norm.stat1);
			norm.i++;
		}
	}
	else if (input->cmd && ft_strlen(input->cmd) > 2)
	{
		norm.tmp = ft_strdup(input->cmd);
		norm.k = stat(norm.tmp, &norm.stat1);
	}
	part_2(&norm, input);
}
