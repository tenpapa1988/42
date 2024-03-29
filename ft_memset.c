/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:01:33 by yussaito          #+#    #+#             */
/*   Updated: 2024/02/21 17:13:34 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len);

int	main(void)
{
	char	buf1[] = "ABCDEF";
	char	buf2[] = "ABCDEF";
	char	buf3[] = "ABC";
	char	buf4[] = "ABC";

	/* case1 */
	printf("ft_memset1 is %s\n", (char *)ft_memset(buf1, '1', 3));
	printf("memset1 is %s\n", (char *)memset(buf2, '1', 3));

	/* case2 -> Undefined behavior*/
	printf("ft_memset2 is %s\n", (char *)ft_memset(buf3, '1', 4));
	printf("memset2 is %s\n", (char *)memset(buf4, '1', 4));
	return (0);	
}

void	*ft_memset(void *b, int c, size_t len)
{
	char	*a;
	int		i;

	a = (char *)b;
	i = 0;
	while (len--)
	{
		a[i] = c;
		i++;
	}
	return ((void *)a);
}
