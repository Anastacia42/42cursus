/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:01:19 by ansilva-          #+#    #+#             */
/*   Updated: 2022/02/23 11:38:33 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	get_len_n(int n)
{
	int	len_n;

	len_n = 0;
	if (n < 0)
		len_n++;
	while (n)
	{
		n /= 10;
		len_n++;
	}
	return (len_n);
}

char	get_str(int n, char *str, int len)
{
	while (n)
	{
		n /= 10;
		str[--len] = 
	}
}

char	*ft_itoa(int n)
{
	int		len_n;
	char	*str;

	len_n = get_len_n(n);
	printf("len_n: %d\n", len_n);
	str = malloc(sizeof(*str) * len_n + 1);
	if (str == NULL)
		return (NULL);
	
	return (str);
}

int	main()
{
	int		n;
	char	*numb;

	n = -245;
	numb = ft_itoa(n);
	printf("%d\n", n);
	printf("%s\n", numb);
	return (0);
}