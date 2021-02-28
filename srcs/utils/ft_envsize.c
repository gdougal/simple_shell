/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:29:12 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/21 20:29:13 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_envsize(t_env *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		if (lst->is_hidden == VISIBLE)
			i++;
		lst = lst->next;
	}
	return (i);
}
