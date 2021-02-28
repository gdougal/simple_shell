/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:43:29 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/21 19:43:31 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		init_env(t_env *lst_env, int status)
{
	lst_env->key = "?";
	lst_env->eq = '=';
	lst_env->value = ft_itoa(status);
	lst_env->is_hidden = INVISIBLE;
}
