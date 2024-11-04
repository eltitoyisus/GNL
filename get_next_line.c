/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:12:13 by marvin            #+#    #+#             */
/*   Updated: 2024/11/04 15:48:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_line_len(int fd)
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

char	*ft_read(int fd, int len)
{
    char	*buffer;
    int		bytes_read;
    int		total_read;

    buffer = (char *)malloc(len + 1);
    if (!buffer)
        return (NULL);

    total_read = 0;
    while (total_read < len)
    {
        bytes_read = read(fd, buffer + total_read, len - total_read);
        if (bytes_read <= 0)
        {
            free(buffer);
            return (NULL);
        }
        total_read += bytes_read;
    }
    buffer[len] = '\0';
    return (buffer);
}

char	*get_next_line(int fd)
{
    char	*line;
    int		len;

    if (fd < 0)
        return (NULL);
    len = ft_line_len(fd);
    if (len <= 0)
        return (NULL);

    line = ft_read(fd, len);
    if (!line)
        return (NULL);

    return (line);
}
