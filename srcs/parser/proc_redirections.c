/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_redirections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 07:39:46 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/25 22:16:12 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	amb_redir(t_input *input)
{
	ft_putstr_fd("Ambiguous redirect\n", 1);
	input->ret_code = 1;
}

static void	not_file(t_input *input)
{
	ft_putstr_fd("No such file or directory\n", 1);
	input->ret_code = 1;
}

void		parse_redirections(char *key_value, t_input *input, char *name)
{
	if (input->fd_fclos)
		close(input->fd_fclos);
	if (!ft_strcmp(key_value, ">>"))
	{
		if ((input->fd_fclos = open(name,
				O_APPEND | O_WRONLY | O_CREAT, 0644)))
			dup2(input->fd_fclos, 1);
		else
			amb_redir(input);
	}
	else if (!ft_strcmp(key_value, ">"))
	{
		if ((input->fd_fclos = open(name,
				O_WRONLY | O_TRUNC | O_CREAT, 0644)))
			dup2(input->fd_fclos, 1);
		else
			amb_redir(input);
	}
	else if (!ft_strcmp(key_value, "<"))
	{
		if ((input->fd_fclos = open(name, O_RDONLY, 0644)))
			dup2(input->fd_fclos, 0);
		else
			not_file(input);
	}
}
