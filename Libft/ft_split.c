/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:00:59 by ansilva-          #+#    #+#             */
/*   Updated: 2022/02/24 15:01:01 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	count_c(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c && i != 0)
			count++;
		i++;
	}
	if (s[--i] != c)
		count++;
	return (count);
}

char	*put_str(char const *s, int *pos, char c)
{
	int		i;
	int		len;
	char	*str;

	while (s[*pos] == c)
		(*pos)++;
	len = 0;
	i = *pos;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	str = malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[*pos];
		i++;
		(*pos)++;
	}
	str[i] = '\0';
	return (str);
}

char	**str_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**arr;
	int		i;
	int		pos;

	if (s == NULL)
		return (NULL);
	count = count_c(s, c);
	arr = malloc(sizeof(*arr) * (count + 1));
	if (arr == NULL)
		return (NULL);
	pos = 0;
	i = 0;
	while (i < count)
	{
		arr[i] = put_str(s, &pos, c);
		if (arr[i] == NULL)
			return (str_free(arr));
		i++;
	}
	arr[i] = 0;
	return (arr);
}
/*
int	main()
{
	char	s[] = "banana amarelo camelo";
	char	c;
	char	**str;
	int		i;
	int		count;

	c = ' ';
	count = count_c(s, c);
	str = ft_split(s, c);
	i = 0;
	while (i < count)
	{
		printf("%s\n", str[i]);
		i++;
	}
	return (0);
}*/