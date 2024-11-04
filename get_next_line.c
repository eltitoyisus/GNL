/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:12:13 by marvin            #+#    #+#             */
/*   Updated: 2024/11/04 17:09:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


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
