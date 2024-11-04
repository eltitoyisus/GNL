/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:30:28 by marvin            #+#    #+#             */
/*   Updated: 2024/11/04 11:48:30 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	char	*s_cpy;

	s_cpy = (char *)s;
	while (*s_cpy)
	{
		if (*s_cpy == (char)c)
			return (s_cpy);
		s_cpy++;
	}
	if ((char)c == '\0')
		return (s_cpy);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		new_str[i] = s[start + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (i < n)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
