/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:20:34 by ansilva-          #+#    #+#             */
/*   Updated: 2022/03/23 13:31:04 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 

char	*update_content(char *content)
{
	char	*updated;
	int		lenght;
	int		index;
	int		position;

	if (!content)
		return (NULL);
	position = 0;
	while (content[position] && content[position] != '\n')
		position++;
	lenght = ft_strlen(content);
	updated = (char *)malloc(sizeof(char) * (lenght - position) + 1);
	if (!updated)
		return (NULL);
	index = 0;
	position++;
	while (index < lenght && content[position] != '\0')
	{
		updated[index] = content[position + index];
		index++;
	}
	updated[index] = '\0';
	free(content);
	return (updated);
}

char	*ft_get_line(char *content)
{
	char	*line;
	int		lenght;
	int		index;

	lenght = 0;
	if (!content[lenght])
		return (NULL);
	while (content[lenght] && content[lenght] != '\n')
		lenght++;
	line = (char *)malloc(sizeof(char) * lenght + 2);
	if (!line)
		return (NULL);
	index = 0;
	while (index < lenght && content[index] != '\n')
	{
		line[index] = content[index];
		index++;
	}
	line[index++] = '\n';
	line[index] = '\0';
	return (line);
}

char	*seek_new_line(char *content, int fd)
{
	char	*buff;
	ssize_t	read_bytes;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(content, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		content = ft_strjoin(content, buff);
	}
	free(buff);
	if (read_bytes == 0)
	{
		free(content);
		return (NULL);
	}
	return (content);
}

char	*get_next_line(int fd)
{
	char		*new_line;
	static char	*content;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!content)
		content = "";
	content = seek_new_line(content, fd);
	if (!content)
		return (NULL);
	new_line = ft_get_line(content);
	content = update_content(content);
	return (new_line);
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("teste.txt", O_RDONLY);
// 	printf("call 1: %s\n", get_next_line(fd));
// 	printf("call 2: %s\n", get_next_line(fd));
// 	printf("call 3: %s\n", get_next_line(fd));
// 	printf("call 4: %s\n", get_next_line(fd));
// 	printf("call 5: %s\n", get_next_line(fd));
// 	printf("call 6: %s\n", get_next_line(fd));
// 	printf("call 7: %s\n", get_next_line(fd));
// 	printf("call 8: %s\n", get_next_line(fd));
// 	printf("call 9: %s\n", get_next_line(fd));
// 	printf("call 10: %s\n", get_next_line(fd));
// 	printf("call 11: %s\n", get_next_line(fd));
// 	close(fd);
// 	return (0);
// }
