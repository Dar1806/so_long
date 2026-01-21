/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:57:16 by nmeunier          #+#    #+#             */
/*   Updated: 2025/11/27 13:57:16 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	slen;
	char	*subs;

	j = 0;
	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (start >= slen)
	{
		subs = malloc(1);
		if (!subs)
			return (0);
		subs[0] = '\0';
		return (subs);
	}
	if (len > slen - start)
		len = slen - start;
	subs = malloc(sizeof(char) * (len + 1));
	if (!subs)
		return (0);
	while (s[start] && j < len)
		subs[j++] = s[start++];
	subs[j] = '\0';
	return (subs);
}

char	*fill_line(int fd, char *buffer, char *left_c)
{
	ssize_t	readf;
	char	*tmp;

	readf = 1;
	while (readf > 0)
	{
		readf = read(fd, buffer, BUFFER_SIZE);
		if (readf == -1)
		{
			free (left_c);
			return (NULL);
		}
		else if (readf == 0)
			break ;
		buffer[readf] = '\0';
		if (!left_c)
			left_c = ft_strdup("");
		tmp = left_c;
		left_c = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_c);
}

static char	*set_line(char *line)
{
	ssize_t	i;
	char	*left_c;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (NULL);
	left_c = ft_substr(line, i + 1, ft_strlen(line) - i - 1);
	if (!left_c || left_c[0] == '\0')
	{
		free(left_c);
		return (NULL);
	}
	line[i + 1] = '\0';
	return (left_c);
}

char	*get_next_line(int fd)
{
	static char	*left_c;
	char		*buffer;
	char		*line;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		free(left_c);
		buffer = NULL;
		left_c = NULL;
		return (NULL);
	}
	line = fill_line(fd, buffer, left_c);
	free(buffer);
	buffer = NULL;
	if (!line)
	{
		left_c = NULL;
		return (NULL);
	}
	left_c = set_line(line);
	return (line);
}
