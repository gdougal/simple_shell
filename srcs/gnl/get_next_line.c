/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <gdougal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 11:30:51 by gdougal           #+#    #+#             */
/*   Updated: 2020/07/20 07:10:20 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "minishell.h"

static char			*tail(char **line, char **rms)
{
	char			*tmp;
	char			*start;

	start = NULL;
	if (*rms)
	{
		if ((start = ft_g_strchr(*rms, '\n')))
		{
			*start = '\0';
			*line = ft_g_strdup(*rms);
			tmp = *rms;
			*rms = ft_g_strdup(start + 1);
			free(tmp);
		}
		else
		{
			*line = ft_g_strdup(*rms);
			free(*rms);
			*rms = NULL;
		}
	}
	else
		*line = ft_g_strdup("");
	return (start);
}

void				ft_ctrl_d(void)
{
	ft_putstr_fd("  \b\b", 1);
	ft_putstr_fd("\nexit\n", 1);
	exit(0);
}

static void			j_line(char **line, char *r_tmp)
{
	char	*tmp;

	tmp = *line;
	*line = ft_g_strjoin(*line, r_tmp);
	free(tmp);
}

int					get_next_line(int fd, char **line)
{
	static char		r_tmp[21];
	char			*rms;
	int				res_read;
	char			*start;

	res_read = 0;
	rms = NULL;
	start = tail(line, &rms);
	while (!start && (res_read = read(fd, r_tmp, 20)) && r_tmp[0] != '\n')
	{
		if (ft_strlen(r_tmp))
			ft_putstr_fd("  \b\b", 1);
		if ((start = ft_g_strchr(r_tmp, '\n')))
		{
			*start = '\0';
			rms = ft_g_strdup(start + 1);
		}
		j_line(line, r_tmp);
	}
	clean_any_arr(rms, NULL);
	if (!res_read)
		ft_ctrl_d();
	return (res_read || rms ? 1 : 0);
}
