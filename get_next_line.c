/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:12:13 by marvin            #+#    #+#             */
/*   Updated: 2024/11/04 16:51:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *str)
{
	char	*bff;
	int		bytes;

	bff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!bff)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(str, '\n') && bytes != 0)
	{
		bytes = read(fd, bff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(bff);
			free(str);
			return (NULL);
		}
		bff[bytes] = '\0';
		str = ft_strjoin(str, bff);
	}
	free(bff);
	return (str);
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
