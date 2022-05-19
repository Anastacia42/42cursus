/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:46:20 by ansilva-          #+#    #+#             */
/*   Updated: 2022/05/19 14:42:09 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signo)
{
	if (signo == SIGUSR1)
		ft_printf("Cheguei aqui!");
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID: %d", pid);
	signal(SIGUSR1, signal_handler);
	return (0);
}
