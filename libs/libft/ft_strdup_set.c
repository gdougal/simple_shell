/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanell <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 14:25:10 by vanell            #+#    #+#             */
/*   Updated: 2020/11/28 14:25:12 by vanell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_set(const char *s, const char *set)
{
	char	*t;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[++i])
	{
		if (is_set(s[i], set, 0))
			break ;
	}
	if (!(t = malloc((i + 1) * sizeof(char))))
		return (NULL);
	t[i] = '\0';
	while (i--)
		t[i] = s[i];
	return (t);
}
