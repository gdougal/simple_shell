/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 07:12:18 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/20 07:12:21 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		length_cmds(char *line, t_flag *flag)
{
	int		k;
	int		i;

	k = 0;
	i = 0;
	while (line[i])
	{
		if (is_set(line[i], "'\"", 0) && line[i - 1] != '\\')
		{
			if (k && k == is_set(line[i], "'\"", 0))
				k = 0;
			else if (!k)
				k = (int)line[i];
		}
		if (!k && (line[i] == ';' || line[i] == '|') && line[i - 1] != '\\')
		{
			flag->length = i;
			flag->delim = line[i];
			return (line[i]);
		}
		i++;
	}
	flag->length = i;
	return (0);
}
