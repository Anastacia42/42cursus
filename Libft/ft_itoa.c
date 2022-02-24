/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:01:19 by ansilva-          #+#    #+#             */
/*   Updated: 2022/02/24 10:38:07 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	get_len_n(int n)
{
	int	len_n;

	len_n = 0;
	if (n <= 0)
		len_n++;
	while (n)
	{
		n /= 10;
		len_n++;
	}
	return (len_n);
}

void	get_str(int n, char *str, int len)
{
	if (n == -2147483648)
	{
		str[1] = '2';
		n = 147483648;
	}
	if (n < 0)
		n = -n;
	while (len >= 0 && str[len] == '\0')
	{
		str[len--] = (n % 10 + 48);
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		len_n;
	char	*str;

	len_n = get_len_n(n);
	str = malloc(sizeof(*str) * (len_n + 1));
	if (str == NULL)
		return (NULL);
	str[len_n] = '\0';
	get_str(n, str, len_n - 1);
	if (n < 0)
		str[0] = '-';
	return (str);
}
/*
int	main()
{
	int		n;
	char	*numb;

	n = 1;
	numb = ft_itoa(n);
	printf("%d\n", n);
	printf("%s\n", numb);
	return (0);
}*/