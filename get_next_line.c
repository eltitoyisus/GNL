/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:12:13 by marvin            #+#    #+#             */
/*   Updated: 2024/11/04 17:56:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buffer)
{
	char	*str;
	int		bytes;

	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(buffer, '\n') && bytes != 0)
	{
		bytes = read(fd, str, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(str);
			return (NULL);
		}
		str[bytes] = '\0';
		buffer = ft_strjoin(buffer, str);
	}
	free(s);
	return (buffer);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s1, len1);
	ft_memcpy(new_str + len1, s2, len2 + 1);
	return (new_str);
}

static char	*ft_line(char *str)
{
    int		i;
    char	*line;

    i = 0;
    if (!str[i])
        return (NULL);
    while (str[i] && str[i] != '\n')
        i++;
    line = ft_substr(str, 0, i + 1);
    return (line);
}

static char	*ft_nextstr(char *str)
{
    int		i;
    char	*nextstr;

    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    if (!str[i])
    {
        free(str);
        return (NULL);
    }
    nextstr = ft_substr(str, i + 1, ft_strlen(str) - i);
    free(str);
    return (nextstr);
}

char	*get_next_line(int fd)
{
    static char	*str;
    char		*line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    str = ft_read(fd, str);
    if (!str)
        return (NULL);

    line = ft_line(str);
    str = ft_nextstr(str);
    return (line);
}
