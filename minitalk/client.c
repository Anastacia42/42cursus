/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:46:33 by ansilva-          #+#    #+#             */
/*   Updated: 2022/05/12 17:16:52 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signo)
{
	if (signo == SIGUSR1)
		ft_printf("Message received successfully!");
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(*argv[1]);
		signal(SIGUSR1, signal_handler);
		kill(pid, argv[2]);
		ft_printf("Estou aqui");
	}
	return (0);
}
