/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:39:38 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/25 22:13:12 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		first_init_and_signals(t_norme_0 *norm, char **envp)
{
	norm->fd_rd = dup(0);
	norm->fd_wt = dup(1);
	norm->status = 0;
	init_env(&norm->lst_env, norm->status);
	norm->lst_env.next = make_envp(envp);
	norm->pip = 0;
	norm->line = NULL;
	signal(SIGQUIT, (void *)signal_ctrl_slash);
	signal(SIGINT, (void *)signal_ctrl_c);
}

void		fd_pipe_changer(t_norme_0 *norm, int i, int j, int flag)
{
	if (!flag)
	{
		norm->pip = PIPE;
		pipe(norm->p_fd);
	}
	else
	{
		dup2(norm->p_fd[i], i);
		close(norm->p_fd[j]);
		if (norm->pip)
			norm->pip = 0;
	}
}

void		fd_close_and_dup(t_norme_0 *norm)
{
	if (norm->input.fd_fclos != -1)
		close(norm->input.fd_fclos);
	dup2(norm->fd_wt, 1);
	dup2(norm->fd_rd, 0);
}

static int	main_body(t_norme_0 *n)
{
	if (n->input.cmd_func != ft_execve && !n->input.pipe)
	{
		n->input.cmd_func(&n->input, &n->lst_env);
		n->status = n->input.ret_code;
	}
	if (n->input.pipe == PIPE && n->input.fd_fclos == -1)
		fd_pipe_changer(n, 1, 0, 0);
	if ((n->pid = fork()) == -1)
		return (1);
	if (!n->pid)
	{
		if (n->input.pipe == PIPE && n->input.fd_fclos == -1)
			fd_pipe_changer(n, 1, 0, 1);
		if (n->input.pipe == PIPE || n->input.cmd_func == ft_execve)
			n->input.cmd_func(&n->input, &n->lst_env);
		exit(n->input.ret_code);
	}
	if (n->pip == PIPE && n->input.fd_fclos == -1)
		fd_pipe_changer(n, 0, 1, 1);
	if (n->input.fd_fclos != -1)
		fd_close_and_dup(n);
	chng_status(&n->lst_env, n->status, &n->input);
	free_input(&n->input);
	return (0);
}

int			main(int argc, char **argv, char **envp)
{
	t_norme_0	norm;

	if (argc > 1)
		return (1);
	*argv = (void*)(*argv);
	first_init_and_signals(&norm, envp);
	while (1)
	{
		ft_putstr_fd("ПОЛУПОДПОДРУЧНЫЙ->", 1);
		if (g_sig_c)
			chng_status(&norm.lst_env, g_sig_c, &norm.input);
		get_next_line(STDIN, &norm.line);
		while (norm.line)
		{
			parser(&norm.line, &norm.lst_env, &norm.input);
			if (norm.input.cmd_func)
				if (main_body(&norm))
					return (1);
			if (norm.input.pipe != PIPE && !norm.pip)
				fd_close_and_dup(&norm);
			chng_status(&norm.lst_env, norm.status, &norm.input);
		}
		waitpid(norm.pid, &norm.status, 0);
		chng_status(&norm.lst_env, norm.status, &norm.input);
	}
	return (0);
}
