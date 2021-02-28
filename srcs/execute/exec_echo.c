/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:22:08 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/25 21:37:48 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	echo_loop_body(int *k, char **arg, int *j, int i)
{
	if (!ft_strcmp(arg[i], "-n") && *j != 2)
	{
		*k = 1;
		*j = 1;
	}
	else
		*j = 2;
	if (*j == 2 || ft_strcmp(arg[i], "-n"))
	{
		ft_putstr_fd(arg[i], 1);
		if (arg[i + 1])
			write(1, " ", 1);
	}
}

void		ft_echo(t_input *input, t_env *env)
{
	int	i;
	int j;
	int	k;

	i = 1;
	j = 0;
	k = 0;
	*env = *env;
	if (input->args)
	{
		while (input->args[i])
		{
			echo_loop_body(&k, input->args, &j, i);
			i++;
		}
	}
	if (!k)
		write(1, "\n", 1);
}
