/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_any_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:51:29 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/22 16:51:31 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	clean_any_arr(char *str, char **strstr)
{
	int	i;

	i = 0;
	if (str)
	{
		free(str);
		str = NULL;
	}
	if (strstr)
	{
		while (strstr[i])
		{
			free(strstr[i]);
			strstr[i] = NULL;
			i++;
		}
		free(strstr);
		strstr = NULL;
	}
}
