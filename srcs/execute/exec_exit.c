/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:48:13 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/25 22:50:02 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_exit(t_input *input, t_env *env)
{
	int	i;
	int j;

	i = 0;
	j = 1;
	*env = *env;
	if (input->args && input->args[j])
	{
		while (ft_isdigit(input->args[j][i]))
			i++;
		if (!input->args[j][i] && !input->args[j + 1])
			exit(ft_atoi(input->args[j]));
		else if (!input->args[j][i] && input->args[j + 1])
		{
			ft_putstr_fd("ПОЛУПОДПОДРУЧНЫЙ: exit: too many arguments\n", 1);
			return ;
		}
		else
		{
			ft_putstr_fd("exit\nПОЛУПОКЕР: ""numeric argument required\n", 1);
			exit(255);
		}
	}
	else
		exit(0);
}
