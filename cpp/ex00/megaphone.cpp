/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 00:47:07 by yussaito          #+#    #+#             */
/*   Updated: 2025/04/03 00:53:00 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	} else {
		for (int i = 1; i < argc; ++i)
		{
			for (int j = 0  ; argv[i][j]; ++j)
			{
				std::cout << static_cast<char>(std::toupper(argv[i][j]));
			}
		}
		std::cout << std::endl;
	}
	return 0;
}