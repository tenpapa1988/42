/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:13:02 by yussaito          #+#    #+#             */
/*   Updated: 2024/01/29 16:22:55 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char *ft_strjoin(int size, char **strs, char *sep);

int main(void)
{
	char *strs[] = {"Hello", "World", "in", "C"};
	char *sep = " ";
	int size = sizeof(strs) / sizeof(strs[0]);

	char *concatenated = ft_strjoin(size, strs, sep);
	if (concatenated == NULL)
	{
		perror("Memory allocation failed");
		return (1);
	}

	printf("Concatenated string: %s\n", concatenated);

	return (0);
}

char *ft_strjoin(int size, char **strs, char *sep) {
    if (size == 0) {
        char *empty_str = (char *)malloc(1);
        if (empty_str != NULL) {
            empty_str[0] = '\0';
        }
        return empty_str;
    }

    // Calculate total length manually
    int total_length = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; strs[i][j] != '\0'; j++) {
            total_length++;
        }
    }
    for (int i = 0; sep[i] != '\0' && size > 1; i++) {
        total_length++;
    }
    total_length++; // For null terminator

    // Allocate memory for the concatenated string
    char *result = (char *)malloc(total_length);
    if (result == NULL) {
        return NULL;
    }

    // Concatenate the strings manually
    int pos = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; strs[i][j] != '\0'; j++) {
            result[pos++] = strs[i][j];
        }
        if (i < size - 1) {
            for (int k = 0; sep[k] != '\0'; k++) {
                result[pos++] = sep[k];
            }
        }
    }
    result[pos] = '\0'; // Null-terminate the string

    return result;
}