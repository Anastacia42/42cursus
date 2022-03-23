/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:20:49 by ansilva-          #+#    #+#             */
/*   Updated: 2022/03/23 12:39:35 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	b;

	b = c;
	i = 0;
	while (s && s[i] && (s[i] != b))
		i++;
	if (s[i] == b)
		return ((char *)s + i);
	else
		return (NULL);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	i;
	size_t	a;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (dstsize == 0 || dstsize <= len_dst)
		return (len_src + dstsize);
	i = 0;
	while (dst[i])
		i++;
	a = 0;
	while (src[a] && (a < (dstsize - len_dst -1)))
	{
		dst[i + a] = src[a];
		a++;
	}
	dst[i + a] = '\0';
	return (len_src + len_dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (src[len])
		len++;
	if (dstsize == 0)
		return (len);
	i = 0;
	while (src && src[i] && (i < dstsize -1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_s1;
	int		len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, len_s1 + 1);
	ft_strlcat(str, s2, len_s1 + len_s2 + 1);
	return (str);
}
