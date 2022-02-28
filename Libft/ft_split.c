/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:00:59 by ansilva-          #+#    #+#             */
/*   Updated: 2022/02/28 13:26:55 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_c(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (c == '\0')
		return (0);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			count++;
		i++;
	}
	if (s[--i] != c)
		count++;
	return (count);
}

static char	*put_str(char const *s, int *pos, char c)
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

static char	**str_free(char **arr)
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
