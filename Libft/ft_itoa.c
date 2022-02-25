/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:01:19 by ansilva-          #+#    #+#             */
/*   Updated: 2022/02/25 16:35:50 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

void	get_str(long int n, char *str, int len)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	else if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[len--] = (n % 10 + 48);
		n /= 10;
		i++;
	}
	str[i + 1] = '\0';
}

char	*ft_itoa(int n)
{
	int		len_n;
	char	*str;

	len_n = get_len_n(n);
	str = malloc(sizeof(*str) * (len_n + 1));
	if (str == NULL)
		return (NULL);
	get_str(n, str, len_n - 1);
	return (str);
}
