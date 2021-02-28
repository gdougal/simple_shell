/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 21:37:16 by gdougal           #+#    #+#             */
/*   Updated: 2020/11/21 21:37:18 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	changer_handle(t_env *lst_env, char *path, int flag)
{
	t_env	*tmp;
	char	*tmp_1;
	char	*env;

	tmp = lst_env;
	if (!flag)
		env = ft_strdup("OLDPWD");
	else
		env = ft_strdup("PWD");
	while (tmp->next)
	{
		if (!ft_strcmp(tmp->key, env))
		{
			tmp_1 = tmp->value;
			tmp->value = path;
			free(tmp_1);
			break ;
		}
		tmp = tmp->next;
	}
	clean_any_arr(env, NULL);
}

static void	env_pwd_changer(t_env *lst_env, char *old)
{
	changer_handle(lst_env, old, 0);
	changer_handle(lst_env, getcwd(NULL, 0), 1);
}

static void	part(t_input *input, int res, t_env *lst_env, char *old_pwd)
{
	if (res == -1)
	{
		ft_putstr_fd("cd: rg: No such file or directory\n", 1);
		input->ret_code = 1;
		return ;
	}
	else if (res == 0)
		env_pwd_changer(lst_env, old_pwd);
}

void		ft_cd(t_input *input, t_env *lst_env)
{
	int		res;
	char	*tmp;
	char	*old_pwd;

	old_pwd = getcwd(NULL, 0);
	if (input->args && input->args[1])
		res = chdir(input->args[1]);
	else
	{
		tmp = ft_strdup(lst_finder_simple("HOME", lst_env));
		res = chdir(tmp);
		clean_any_arr(tmp, NULL);
		if (res == -1)
		{
			ft_putstr_fd("HOME not set\n", 1);
			input->ret_code = 1;
			return ;
		}
	}
	part(input, res, lst_env, old_pwd);
}
