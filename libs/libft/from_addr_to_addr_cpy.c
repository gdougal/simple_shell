/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_addr_to_addr_cpy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanell <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 21:24:28 by vanell            #+#    #+#             */
/*   Updated: 2020/11/26 21:24:30 by vanell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*from_addr_to_addr_cpy(char *str1, char *str2)
{
	char	*t;
	size_t	i;

	i = (str1 < str2 ? str2 - str1 : str1 - str2);
	t = malloc((i + 1) * sizeof(char));
	if (!t)
		return (NULL);
	t[i] = '\0';
	while (i--)
		t[i] = str2[i];
	return (t);
}
