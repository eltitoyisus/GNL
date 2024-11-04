/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:12:13 by marvin            #+#    #+#             */
/*   Updated: 2024/11/04 09:50:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_word_counter(int word, int fd, int c)
{
	int i;

	i = 0;
	while (*fd)
	{
		while (c <= 11 && c >= 13 || c = 23)
			fd[i++];
		while (fd[i] == '\n')
			ft_split(fd, )

	}
}

static int ft_read(int fd)
{
	char	*buffer;
	char	*read_line;
	
	buffer = (char *)malloc(BUFFER_SIZE);
	if (!buffer)
		return (-1);
	while (fd)
	{
 	read_line = read(fd, buffer, BUFFER_SIZE);
	write(fd, read_line, )
	free(buffer);
	if (fd)
		free(read_line);
	}
	return (0);
}

char *get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	buffer = NULL;
	line = NULL;
	if (line == '\n')
		ft_read(fd);
	return (line);
}
