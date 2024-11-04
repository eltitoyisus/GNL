/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:12:13 by marvin            #+#    #+#             */
/*   Updated: 2024/11/04 11:49:54 by jramos-a         ###   ########.fr       */
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
	int	len;

	len = 0;
	while (fd)
	{
		while (fd != '\0')
		{
			len++;
		}
	}
	return (len);
}

static int	ft_read(int fd)
{
	char	*buffer;
	char	read_line;
	int		a;

	a = ft_line_len(fd);
	buffer = (char *)malloc(BUFFER_SIZE);
	if (!buffer)
		return (-1);
	while (fd)
	{
		read_line = read(fd, buffer, BUFFER_SIZE);
		write(fd, read_line, a);
		free(buffer);
		if (fd)
			free(read_line);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;

	buffer = NULL;
	line = NULL;
	if (line == '\n')
		ft_read(fd);
	return (line);
}
