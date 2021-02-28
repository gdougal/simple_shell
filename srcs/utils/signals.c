/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_ctrl_slash.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:01:55 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/25 21:40:08 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_ctrl_slash(void)
{
	int pid;

	pid = waitpid(-1, NULL, WNOHANG);
	if (!pid)
	{
		ft_putendl_fd("\b\b  \b\bQuit: 3", 1);
		g_sig_c = 131;
	}
	else
		ft_putstr_fd("\b\b  \b\b", 1);
}

void	signal_ctrl_c(void)
{
	int pid;

	g_sig_c = 1;
	pid = waitpid(-1, NULL, WNOHANG);
	if (pid)
	{
		ft_putstr_fd("\b\b  \nПОЛУПОДПОДРУЧНЫЙ->", 1);
		g_sig_c = 1;
	}
	if (!pid)
		g_sig_c = 130;
}
