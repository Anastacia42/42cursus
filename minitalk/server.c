/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:46:20 by ansilva-          #+#    #+#             */
/*   Updated: 2022/05/24 16:47:15 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	conversion_to_decimal(int *binary_message)
{
	int	bit;
	int	index;
	int	message_decimal;

	message_decimal = 0;
	index = 0;
	bit = 128;
	while (bit > 0)
	{
		message_decimal += binary_message[index] * bit;
		bit /= 2;
	}
	ft_printf("%c", (char)message_decimal);
}

void	receive_message(int signo, siginfo_t *info, void *nothing)
{
	static char	byte_of_message[9];
	static int	index;

	(void)info;
	(void)nothing;
	if (index == 0)
	{
		ft_memset(byte_of_message, '0', 8);
		byte_of_message[8] = '\0';
	}
	if (signo == SIGUSR1)
		byte_of_message[index] = '1';
	index++;
	if (index == 8)
		ft_printf("%d", byte_of_message);
	// 	conversion_to_decimal(byte_of_message);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action_server;
	sigset_t			block_signal;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	sigemptyset(&block_signal);
	sigaddset(&block_signal, SIGUSR1);
	sigaddset(&block_signal, SIGUSR2);
	action_server.sa_mask = block_signal;
	action_server.__sigaction_u.__sa_sigaction = &receive_message;
	sigaction(SIGUSR1, &action_server, NULL);
	sigaction(SIGUSR2, &action_server, NULL);
	while (1)
		pause();
	return (0);
}
