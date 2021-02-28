/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 11:22:44 by gdougal           #+#    #+#             */
/*   Updated: 2020/11/30 11:22:45 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_set(char c, const char *set, int ret_code)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return ((int)c);
		i++;
	}
	return (ret_code);
}
