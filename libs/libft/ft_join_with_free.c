/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_with_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:58:24 by gdougal           #+#    #+#             */
/*   Updated: 2020/12/22 16:58:26 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join_with_free(char *line, char *line_1)
{
	char *tmp;

	tmp = line;
	line = ft_strjoin(line, line_1);
	free(tmp);
	return (line);
}
