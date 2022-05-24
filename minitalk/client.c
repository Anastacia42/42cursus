/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:46:33 by ansilva-          #+#    #+#             */
/*   Updated: 2022/05/24 16:40:47 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// SIGUSR1 == 1
// SIGUSR2 == 0

void	send_message(char *server_pid, char *message)
{
	pid_t	pid;
	int		index;
	int		bit;

	pid = ft_atoi(server_pid);
	index = 0;
	while (message[index])
	{
		bit = 128;
		while (bit > 0)
		{
			if (((unsigned char)message[index] & bit) == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit /= 2;
		}
		index++;
	}
}

void	handler(int signo)
{
	if (signo != SIGUSR1)
		return ;
	ft_printf("Message succesfully received!");
}

int	main(int argc, char **argv)
{
	struct sigaction	action_client;

	if (argc != 3)
	{
		ft_printf("Invalid arguments!\n ");
		ft_printf("Expected: ./client [server PID] [message]\n");
		return (0);
	}
	sigemptyset(&action_client.sa_mask);
	action_client.__sigaction_u.__sa_handler = &handler;
	if (sigaction(SIGUSR1, &action_client, NULL) == -1)
	{
		ft_printf("sigaction failed!\n");
		return (0);
	}
	send_message(argv[1], argv[2]);
	return (0);
}
