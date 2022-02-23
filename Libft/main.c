/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:20:48 by ansilva-          #+#    #+#             */
/*   Updated: 2022/02/18 14:04:38 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main()
{
	char	src[14] = "  $$123 ";
	int		num;
	int		test;

	num = ft_atoi(src);
	printf("meu resultado %d\n", num);
	test = atoi(src);
	printf("atoi real %d\n", test);
	return (0);
}
