/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_ch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 06:25:30 by gdougal           #+#    #+#             */
/*   Updated: 2020/11/27 06:25:32 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_ch(const char *s, char c, int k)
{
	char	*t;
	size_t	i;

	i = 0;
	while (s[i + k] && s[i] != c)
		i++;
	i += k;
	if (!(t = malloc((i + 1) * sizeof(char))))
		return (NULL);
	t[i] = '\0';
	while (i)
	{
		t[i] = s[i];
		--i;
	}
	return (t);
}
