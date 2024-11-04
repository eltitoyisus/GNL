/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:12:13 by marvin            #+#    #+#             */
/*   Updated: 2024/11/04 17:11:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *str)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	if (!str)
		str = ft_strjoin("", buffer);
	else
	{
		char *temp = str;
		str = ft_strjoin(str, buffer);
		free(temp);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
    static char	*str;
    char		*line;
    char		*temp;
    int			ret;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    line = ft_read(fd, str);
    if (!line)
        return (NULL);
    ret = 1;
    while (ret > 0)
    {
        temp = ft_read(fd, str);
        if (!temp)
            return (NULL);
        if (temp[0] == '\0')
        {
            free(temp);
            break ;
        }
        line = ft_strjoin(line, temp);
        free(temp);
    }
    str = ft_strchr(line, '\n');
    if (str)
    {
        str++;
        str = ft_strjoin("", str);
    }
    return (line);
}
