/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:20:34 by ansilva-          #+#    #+#             */
/*   Updated: 2022/03/18 11:27:24 by ansilva-         ###   ########.fr       */
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

	lenght = 0;
	position = 0;
	while (content[lenght] != '\0')
	{
		if (content[lenght] == '\n' && position == 0)
			position = lenght;
		lenght++;
	}
	updated = malloc(sizeof(char *) * (lenght - position) + 1);
	if (updated == NULL)
		return (NULL);
	index = 0;
	position++;
	while (index < (lenght - position) && content[position] != '\0')
	{
		updated[index] = content[position + index];
		index++;
	}
	updated[index] = '\0';
	return (updated);
}

char	*ft_get_line(char *content)
{
	char	*line;
	int		lenght;
	int		index;

	lenght = 0;
	while (content[lenght] != '\n' && content[lenght] != '\0')
		lenght++;
	line = malloc(sizeof(char *) * lenght + 2);
	if (line == NULL)
		return (NULL);
	index = 0;
	while (index < lenght && content[index] != '\0')
	{
		line[index] = content[index];
		index++;
	}
	line[index++] = '\n';
	line[index] = '\0';
	return (line);
}

char	*seek_new_line(char *content, char *buff, int fd, ssize_t read_bytes)
{
	char	*save_content;

	save_content = ft_strjoin(content, buff);
	while (!ft_strchr(save_content, '\n'))
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		buff[read_bytes] = '\0';
		save_content = ft_strjoin(save_content, buff);
	}
	return (save_content);
}

char	*get_next_line(int fd)
{
	ssize_t		read_bytes;
	static char	buff[BUFFER_SIZE + 1];
	char		*new_line;
	static char	*content;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	new_line = NULL;
	read_bytes = read(fd, buff, BUFFER_SIZE);
	buff[read_bytes] = '\0';
	if (!content)
		content = "";
	if (read_bytes != 0)
	{
		content = seek_new_line(content, buff, fd, read_bytes);
		new_line = ft_get_line(content);
		content = update_content(content);
	}
	return (new_line);
}

int	main(void)
{
	int	fd;

	fd = open("teste.txt", O_RDONLY);
	printf("first call: %s\n", get_next_line(fd));
	printf("second call: %s\n", get_next_line(fd));
	printf("third call: %s\n", get_next_line(fd));
	printf("forth call: %s\n", get_next_line(fd));
	printf("fifth call: %s\n", get_next_line(fd));
	printf("sixth call: %s\n", get_next_line(fd));
	printf("seventh call: %s\n", get_next_line(fd));
	printf("eighth call: %s\n", get_next_line(fd));
	close(fd);
	return (0);
}
