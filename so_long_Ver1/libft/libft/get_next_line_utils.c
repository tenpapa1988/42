/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:23:40 by yussaito          #+#    #+#             */
/*   Updated: 2024/10/23 09:33:56 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_check_s1(char **s1)
{
	if (!*s1)
	{
		*s1 = (char *)malloc(1 * sizeof(char));
		if (!*s1)
			return ;
		*s1[0] = '\0';
	}
}

char	*ft_strchr_g(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin_g(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*rtn;

	ft_check_s1(&s1);
	if (!s1 || !s2)
		return (NULL);
	rtn = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!rtn)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	c = 0;
	if (s1)
		while (s1[++i] != '\0')
			rtn[i] = s1[i];
	while (s2[c] != '\0')
		rtn[i++] = s2[c++];
	rtn[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (rtn);
}
