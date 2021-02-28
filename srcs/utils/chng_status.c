/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chng_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:46:37 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/21 19:46:39 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		chng_status(t_env *lst_env, int status, t_input *input)
{
	if (status && !(status %= 255))
		status = 255;
	else if (input->ret_code && !status)
		status = input->ret_code;
	clean_any_arr(lst_env->value, NULL);
	lst_env->value = ft_itoa(status);
	if (g_sig_c)
		g_sig_c = 0;
}
