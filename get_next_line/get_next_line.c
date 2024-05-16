/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 08:56:54 by yussaito          #+#    #+#             */
/*   Updated: 2024/05/16 10:48:17 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line;
	size_t		len;

	line = NULL;
	len = 0;
	if (fd < 0)
		return (NULL);
	line = ft_read(fd, line, &len);
	if (len == 0 && line)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	if (line)
		line[len] = '\0';
	return (line);
}
