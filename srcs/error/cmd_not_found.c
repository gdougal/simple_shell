/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_not_found.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 00:58:06 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/25 21:36:59 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_not_found(t_input *input, t_env *lst_env)
{
	*lst_env = *lst_env;
	ft_putstr_fd("ПОЛУПОДПОДРУЧНЫЙ: ", 1);
	ft_putstr_fd(input->cmd, 1);
	ft_putstr_fd(": command not found\n", 1);
	input->ret_code = 127;
}

void	arg_req(t_input *input, t_env *lst_env)
{
	*lst_env = *lst_env;
	ft_putstr_fd("ПОЛУПОДПОДРУЧНЫЙ: .: filename "
				"argument required\n.: usage: . "
					"filename [arguments]\n", 1);
	input->ret_code = 2;
}

void	is_a_dir(t_input *input, t_env *lst_env)
{
	*lst_env = *lst_env;
	ft_putstr_fd("ПОЛУПОДПОДРУЧНЫЙ: is a directory\n", 1);
	input->ret_code = 126;
}
