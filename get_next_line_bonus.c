/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:31:33 by abenkrar          #+#    #+#             */
/*   Updated: 2024/12/09 14:24:13 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*creat_rest(int fd, char *rest)
{
	char	*buffer;
	ssize_t	readed_bytes;
	char	*rest_clean;

	readed_bytes = 1;
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (ft_strchr(rest, '\n') == NULL && readed_bytes != 0)
	{
		readed_bytes = read(fd, buffer, BUFFER_SIZE);
		if (readed_bytes < 1)
		{
			free(buffer);
			free(rest);
			return (NULL);
		}
		buffer[readed_bytes] = '\0';
		rest_clean = rest;
		rest = ft_strjoin(rest_clean, buffer);
		free(rest_clean);
	}
	free(buffer);
	return (rest);
}

static char	*creat_line(char **rest)
{
	char	*line;
	char	*rest_clean;
	int		i;

	i = 0;
	while (*((*rest) + i) != '\n' && *((*rest) + i) != '\0')
	{
		i++;
	}
	i++;
	line = ft_substr(*rest, 0, i);
	rest_clean = *rest;
	*rest = ft_substr(rest_clean, i, ft_strlen(rest_clean) - i);
	free(rest_clean);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*rest[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	if (!rest[fd])
	{
		rest[fd] = malloc(1);
		if (!rest[fd])
			return (NULL);
		rest[fd][0] = '\0';
	}
	rest[fd] = creat_rest(fd, rest[fd]);
	if (!rest[fd])
		return (NULL);
	line = creat_line(&rest[fd]);
	return (line);
}
int main()
{
	int fd1 = open("test.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	char *str1;
	char *str2;
	
	str1 = get_next_line(fd1);
	printf("%s", str1);
	free(str1);

	str2 = get_next_line(fd2);
	printf("%s", str2);
	free(str2);

	str1 = get_next_line(fd1);
	printf("%s", str1);
	free(str1);

	str2 = get_next_line(fd2);
	printf("%s", str2);
	free(str2);

	while ((str1= get_next_line(fd1)) != NULL)
	{
		str1 = get_next_line(fd1);
		free(str1);
	}
	while ((str2= get_next_line(fd2)) != NULL)
	{
		str2 = get_next_line(fd2);
		free(str2);
	}
}
