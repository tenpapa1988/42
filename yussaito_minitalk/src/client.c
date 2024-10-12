/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:20:45 by yussaito          #+#    #+#             */
/*   Updated: 2024/10/02 14:41:10 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

static void action(int sig)
{
    static int received = 0;

    if (sig == SIGUSR1)
    {
        printf("Received SIGUSR1 from server\n");
        ++received;
        printf("Received %d bits, continuing to send next bit...\n", received);
        // 次のビットを送信
        printf("Sending next bit...\n");  // ここで次のビット送信を確認
    }
    else if (sig == SIGUSR2)
    {
        printf("Received SIGUSR2 from server (end of message)\n");
        ft_putnbr_fd(received, 1);
        ft_putchar_fd('\n', 1);
        exit(0);
    }
    else
    {
        printf("Unexpected signal: %d\n", sig);
    }
}


static void mt_kill(int pid, char *str)
{
    int     i;
    char    c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			int bit = (c >> i) & 1;  // 送信するビットを確認
			printf("Sending bit: %d for character: %c\n", bit, c);
			if (bit == 1)
			{
				kill(pid, SIGUSR2);  // 1ビットを送信
			}
			else
			{
				kill(pid, SIGUSR1);  // 0ビットを送信
			}
			usleep(10000);  // 送信間隔
			pause();  // サーバーからの確認応答を待つ
			printf("Received server response, continue sending\n");
		}
	}

    // 文字列の終了シグナルを送信
    i = 8;
    while (i--)
    {
        kill(pid, SIGUSR1);  // 0の送信で終了通知
        usleep(10000);  // 送信間隔
        pause();  // サーバーからの確認応答を待つ
    }
}

int main(int argc, char **argv)
{
    if (argc != 3 || !ft_strlen(argv[2]))
        return (1);

    // シグナルハンドラの設定
    signal(SIGUSR1, action);
    signal(SIGUSR2, action);

    ft_putstr_fd("Sent    : ", 1);
    ft_putnbr_fd(ft_strlen(argv[2]), 1);
    ft_putchar_fd('\n', 1);
    ft_putstr_fd("Received: ", 1);

    mt_kill(ft_atoi(argv[1]), argv[2]);

    while (1)
        pause();  // サーバーからの応答を待ち続ける
    return (0);
}
