/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lines_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:30:28 by marvin            #+#    #+#             */
/*   Updated: 2024/10/13 15:30:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*s3;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s3 = (char *)malloc(len1 + len2 + 1);
	if (!s3)
		return (NULL);
	ft_memcpy(s3, s1, len1);
	ft_memcpy(s3 + len1, s2, len2 + 1);
	return (s3);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*str;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, len);
	str[len] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

char	*ft_strrchr(const char *s, int c)
{
	const char	*i;

	i = 0;
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			i = s;
		}
		s++;
	}
	if (*s == (char)c)
	{
		i = s;
	}
	return ((char *)i);
}
