/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:12:13 by marvin            #+#    #+#             */
/*   Updated: 2024/11/04 16:23:36 by marvin           ###   ########.fr       */
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
    while (!ft_strchr(str, '\n') && total_read != 0)
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
char	*ft_line(char *str)
{
	int		i;
	char	*nw;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	nw = (char *)malloc(sizeof(char) * (i + 2));
	if (!nw)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		nw[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		nw[i] = str[i];
		i++;
	}
	nw[i] = '\0';
	return (nw);
}

char	*get_next_line(int fd)
{
	char		*ln;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read(fd, str);
	if (!str)
		return (0);
	ln = ft_line(str);
	str = ft_nextstr(str);
	return (ln);
}
