/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:21:10 by yussaito          #+#    #+#             */
/*   Updated: 2024/10/03 07:10:21 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include "../libft/libft.h"

static void	action(int sig, siginfo_t *info, void *context)
{
    static int              i = 0;
    static pid_t            client_pid = 0;
    static unsigned char    c = 0;

    (void)context;

    // 受信したシグナルの番号を確認するために表示
    printf("Received signal: %d from PID: %d\n", sig, info->si_pid);
    fflush(stdout);

    if (sig != SIGUSR1 && sig != SIGUSR2)  // SIGUSR1またはSIGUSR2以外の場合は無視
    {
        printf("Unexpected signal: %d\n", sig);
		fflush(stdout);  // 確実に出力する
        return;
    }

    if (!client_pid)
        client_pid = info->si_pid;

    printf("Processing bit...\n");
    fflush(stdout);

    // SIGUSR2 が 1 ビット、SIGUSR1 が 0 ビットとして扱う
    c |= (sig == SIGUSR2);  
    if (++i == 8)  // 8ビットが揃ったら1文字完成
    {
        i = 0;
        if (!c)  // NULL文字の場合は終了シグナル
        {
            printf("End of message. Sending SIGUSR2 to client.\n");
            fflush(stdout);
            kill(client_pid, SIGUSR2);  // 文字列終了通知
            client_pid = 0;
            return;
        }
        // 完成した文字を表示
        ft_putchar_fd(c, 1);
        printf("Current character: %c\n", c);  // デバッグ出力
        fflush(stdout);
        c = 0;
    }
    else
    {
        c <<= 1;  // 次のビットの準備
        printf("Shifted bit, ready for next bit.\n");
        fflush(stdout);
    }

    // クライアントに確認応答を送信
    printf("Sending SIGUSR1 to client to request next bit.\n");
    fflush(stdout);
    kill(client_pid, SIGUSR1);
}

int	main(void)
{
    struct sigaction	sa;

    // シグナルのハンドラ関数を設定
    sa.sa_sigaction = action;
    sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);

    // サーバーのPIDを表示
    ft_putstr_fd("Server PID: ", 1);
    ft_putnbr_fd(getpid(), 1);
    ft_putchar_fd('\n', 1);

    // シグナルハンドラの設定
    sigaction(SIGUSR1, &sa, 0);
    sigaction(SIGUSR2, &sa, 0);

    // サーバーは無限ループでシグナルを待機
    while (1)
        pause();

    return (0);
}
