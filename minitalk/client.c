/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:46:33 by ansilva-          #+#    #+#             */
/*   Updated: 2022/05/19 16:29:13 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int		pid;
	int		message_int;
	char	*message_char;
	char	*base;

	if (argc < 3)
		return (0);
	pid = ft_atoi(argv[1]);
	ft_printf("server_pid: %d\n", pid);
	message_int = ft_atoi(argv[2]);
	ft_printf("message_int: %d\n", message_int);
	base = "01";
	message_char = ft_put_base(message_int, base);
	ft_printf("message_char: %s\n", message_char);
	message_int = ft_atoi(message_char);
	kill(pid, message_int);
	return (0);
}
