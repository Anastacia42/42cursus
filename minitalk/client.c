/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:46:33 by ansilva-          #+#    #+#             */
/*   Updated: 2022/06/08 14:07:16 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// SIGUSR1 == 1
// SIGUSR2 == 0

void	send_message(int pid, char *message)
{
	int		index;
	int		bit;
	char	c;

	index = 0;
	while (message[index])
	{
		c = message[index];
		bit = 128;
		while (bit > 0)
		{
			if ((c & bit) == bit)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit /= 2;
			usleep(100);
		}
		index++;
	}
}

void	handler(int signo)
{
	if (signo == SIGUSR1)
		ft_printf("Message successfully received!\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	action_client;

	if (argc != 3)
	{
		ft_printf("Invalid arguments!\n");
		ft_printf("Expected: ./client [server PID] [message]\n");
		return (0);
	}
	sigemptyset(&action_client.sa_mask);
	action_client.__sigaction_u.__sa_handler = &handler;
	signal(SIGUSR1, handler);
	// if (sigaction(SIGUSR1, &action_client, NULL) == -1)
	// {
	// 	ft_printf("sigaction failed!\n");
	// 	return (0);
	// }
	send_message(ft_atoi(argv[1]), argv[2]);
	return (0);
}

