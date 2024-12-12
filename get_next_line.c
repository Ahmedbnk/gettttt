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

#include "get_next_line.h"

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
	static char	*rest;
	char		*main_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (rest == NULL)
	{
		rest = malloc(1);
		rest[0] = '\0';
	}
	rest = creat_rest(fd, rest);
	if (rest == NULL)
		return (NULL);
	main_line = creat_line(&rest);
	return (main_line);
}
