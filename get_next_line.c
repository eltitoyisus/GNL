/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:12:13 by marvin            #+#    #+#             */
/*   Updated: 2024/11/04 15:20:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_word(const char *s, char c)
{
	int	word;

	word = 0;
	if (!s)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			word++;
			while (*s && *s != c)
				s++;
		}
	}
	return (word);
}

static int	ft_line_len(int fd)
{
	int		len;
	char	buffer;
	int		bytes_read;

	len = 0;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, &buffer, 1);
		if (bytes_read > 0)
		{
			len++;
			if (buffer == '\n')
				bytes_read = 0;
		}
	}
	return (len);
}

static int	ft_read(int fd)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc(BUFFER_SIZE);
	if (!buffer)
		return (-1);
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		write(1, buffer, bytes_read);
	}
	free(buffer);
	if (bytes_read == -1)
		return (-1);
	return (0);
}

char	*get_next_line(int fd)
{
	char	*line;
	int		len;
	int		bytes_read;
	char	buffer;

	if (fd < 0)
		return (NULL);

	len = ft_line_len(fd);
	if (len <= 0)
		return (NULL);

	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);

	bytes_read = read(fd, line, len);
	if (bytes_read <= 0)
	{
		free(line);
		return (NULL);
	}

	line[len] = '\0';
	return (line);
}
