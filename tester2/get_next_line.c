/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 08:56:54 by yussaito          #+#    #+#             */
/*   Updated: 2024/05/14 11:08:31 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	int		i;
	ssize_t	n;

	if (fd < 0)
		return NULL;
	char *line = malloc(BUFFER_SIZE * sizeof(char));  // Allocate initial buffer
	if (!line)
		return (NULL);  // Return NULL if malloc failed
	i = 0;
	line = ft_read(&n, &i, line, fd);
    if (!line || (n <= 0 && i == 0))
	{  // No data read or error occurred
        free(line);
        return (NULL);
    }
	line[i] = '\0';  // Null-terminate the string
	if (n == 0 && i != 0)
		return (line);
	return (line);
}
