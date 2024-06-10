/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 08:56:54 by yussaito          #+#    #+#             */
/*   Updated: 2024/06/04 14:47:25 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_s(int *i, int *c, char *save, char *s)
{
	(*i)++;
	*c = 0;
	while (save[*i])
		s[(*c)++] = save[(*i)++];
	s[*c] = '\0';
	return (s);
}

char	*ft_save(char *save)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	s = (char *)malloc((ft_strlen(save) - i + 1) * sizeof(char));
	if (!s)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	ft_s(&i, &c, save, s);
	free(save);
	return (s);
}

char	*ft_get_line(char *save)
{
	int		i;
	char	*rtn;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	rtn = (char *)malloc((i + 2) * sizeof(char));
	if (!rtn)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		rtn[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		rtn[i] = '\n';
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

char	*ft_read(int fd, char *save)
{
	char	*tmp;
	ssize_t	read_rtn;

	tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	read_rtn = 1;
	while (!ft_strchr(save, '\n') && read_rtn != 0)
	{
		read_rtn = read(fd, tmp, BUFFER_SIZE);
		if (read_rtn == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[read_rtn] = '\0';
		save = ft_strjoin(save, tmp);
	}
	free(tmp);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = ft_read(fd, save);
	if (!tmp)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	save = tmp;
	line = ft_get_line(save);
	save = ft_save(save);
	return (line);
}
