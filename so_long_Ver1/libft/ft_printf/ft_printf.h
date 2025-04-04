/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 10:11:30 by yussaito          #+#    #+#             */
/*   Updated: 2024/10/27 12:37:27 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

int		ft_printf(const char *fmt, ...);
char	*ft_utoa(unsigned int n);
void	ft_print_str(char *c, int *len);
void	ft_print_int(int c, int *len);
void	ft_print_hex_up_x(unsigned int c, int *len);
void	ft_print_hex_p(void *ptr, int *len);
void	ft_print_hex_low_x(unsigned int c, int *len);
void	ft_print_deci(unsigned int c, int *len);
void	ft_print_char(int i, int *len);

#endif