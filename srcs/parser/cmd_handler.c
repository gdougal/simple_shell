/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanell <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 19:33:46 by vanell            #+#    #+#             */
/*   Updated: 2020/12/09 22:24:58 by vanell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	command_handler(t_input *input)
{
	if (!input->cmd)
	{
		ft_putstr_fd("ПОЛУПОДПОДРУЧНЫЙ: : command not found\n", 1);
		return ;
	}
	if (!ft_strcmp(input->cmd, "echo"))
		input->cmd_func = ft_echo;
	else if (!ft_strcmp(input->cmd, "cd"))
		input->cmd_func = ft_cd;
	else if (!ft_strcmp(input->cmd, "pwd"))
		input->cmd_func = ft_pwd;
	else if (!ft_strcmp(input->cmd, "export"))
		input->cmd_func = ft_export;
	else if (!ft_strcmp(input->cmd, "unset"))
		input->cmd_func = ft_unset;
	else if (!ft_strcmp(input->cmd, "env"))
		input->cmd_func = ft_env;
	else if (!ft_strcmp(input->cmd, "exit"))
		input->cmd_func = ft_exit;
	else
		input->cmd_func = ft_execve;
}
