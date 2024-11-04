/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:12:13 by marvin            #+#    #+#             */
/*   Updated: 2024/11/04 16:17:31 by marvin           ###   ########.fr       */
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

char	*ft_read(int fd, char *str)
{
    char	*buffer;
    int		total_read;

    str = ft_strjoin(str, buffer);
    buffer = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    total_read = 1;
    while (!ft_strchr(str, '\n') && total_read < BUFFER_SIZE)
    {
        total_read = read(fd, buffer, BUFFER_SIZE);
        if (total_read == -1)
        {
            free(buffer);
            return (NULL);
        }
        buffer[total_read] = '\0';
        if (!str)
        {
            free(buffer);
            return (NULL);
        }
    }
    free(buffer);
    return (NULL);
}

char	*get_next_line(int fd)
{
    char	*line;
    char	*temp;
    int		len;

    if (fd < 0)
        return (NULL);
    line = ft_read(fd, NULL);
    if (!line)
        return (NULL);
    while (!ft_strchr(line, '\n'))
    {
        temp = ft_read(fd, NULL);
        if (!temp)
        {
            free(line);
            return (NULL);
        }
        char *joined_line = ft_strjoin(line, temp);
        free(line);
        free(temp);
        line = joined_line;
        if (!line)
            return (NULL);
    }
    return (line);
}
