/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:12:13 by marvin            #+#    #+#             */
/*   Updated: 2024/11/04 19:01:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = ft_substr(buffer, 0, i + ft_endl(buffer));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*ft_nextstr(char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	i++;
	j = 0;
	while (buffer[i])
		str[j++] = buffer[i++];
	str[j] = '\0';
	free(buffer);
	return (str);
}

char	*ft_read(int fd, char *buffer)
{
	char	*s;
	int		bytes;

	s = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!s)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(buffer, '\n') && bytes != 0)
	{
		bytes = read(fd, s, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(s);
			return (NULL);
		}
		s[bytes] = '\0';
		buffer = ft_strjoin(buffer, s);
	}
	free(s);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_nextstr(buffer);
	return (line);
}
