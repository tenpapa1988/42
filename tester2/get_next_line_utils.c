/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:23:40 by yussaito          #+#    #+#             */
/*   Updated: 2024/05/14 10:36:49 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dst);
}

void	*my_realloc(void *ptr, size_t new_size)
{
	size_t	old_size;
	size_t	copy_size;
	void	*new_ptr;

    if (new_size == 0)
	{
        free(ptr);
        return (NULL);
    }
	else if (!ptr)
        return malloc(new_size); // 新しいメモリ領域を確保する
    else
	{
		new_ptr = malloc(new_size); // 新しいサイズで新しいメモリ領域を確保する
        if (!new_ptr)
            return (NULL);  // メモリ確保に失敗した場合はNULLを返す
		old_size = BUFFER_SIZE;

		if (old_size < new_size) // コピーするデータ量は、新旧サイズの小さい方を使用
			copy_size = old_size;
		else copy_size = new_size;
        ft_memcpy(new_ptr, ptr, copy_size); // 古いメモリ領域を解放する
        free(ptr); // 新しいサイズをグローバル変数に記録
        return (new_ptr);
    }
}

char	*ft_read(ssize_t *n, int *i, char *line, int fd)
{
	char	buff;

	while ((*n = read(fd, &buff, 1)) > 0)
	{
		if (buff == '\n')
		{
			line[(*i)++] = '\n';
			break;  // Stop at newline
		}
		line[(*i)++] = buff;
		if (*i >= BUFFER_SIZE -1)  // Check if we need more space, leaving room for null terminator
		{
			char *new_line = my_realloc(line, ((*i) + BUFFER_SIZE) * sizeof(char));
			if (!new_line)
			{
				free(line);
				return (NULL);  // Return NULL if realloc failed
			}
            line = new_line;
        }
    }
	return (line);
}
