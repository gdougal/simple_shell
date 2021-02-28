/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:26:27 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/21 20:26:29 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		input_init(t_input *input)
{
	(input)->cmd = NULL;
	(input)->args = NULL;
	(input)->cmd_func = NULL;
	(input)->env_new = NULL;
	(input)->pipe = 0;
	(input)->ret_code = 0;
	input->fd_fclos = -1;
}
