/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:12:19 by abenkrar          #+#    #+#             */
/*   Updated: 2024/12/11 14:12:21 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*p_joined;

	if (s1 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	p_joined = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (p_joined == NULL)
		return (NULL);
	ft_memcpy(p_joined, s1, s1_len);
	ft_memcpy((p_joined + s1_len), s2, s2_len);
	p_joined[s1_len + s2_len] = '\0';
	return (p_joined);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	s_length;

	if (s == NULL)
		return (NULL);
	s_length = ft_strlen(s);
	if (start >= s_length)
	{
		p = malloc(1);
		p[0] = '\0';
		return (p);
	}
	p = malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	p = ft_memcpy(p, (s + start), len);
	p[len] = '\0';
	return (p);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*p_src;
	char	*p_dest;

	i = 0;
	if ((!dest && !src) || n == 0)
		return (dest);
	p_src = (char *)(src);
	p_dest = (char *)(dest);
	while (i < n)
	{
		p_dest[i] = p_src[i];
		i++;
	}
	return (dest);
}
