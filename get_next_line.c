/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:12:13 by marvin            #+#    #+#             */
/*   Updated: 2024/10/01 14:12:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

int ft_read(int fd)
{
	char	*buffer;
	
	buffer = (char *)malloc(BUFFER_SIZE);
	if (!buffer)
		return (-1);
 	read(fd, buffer, BUFFER_SIZE);
	free(buffer);
	return (0);
}

size_t ft_word(int fd, char ***words)
{
	char *line, **temp_words = malloc(10 * sizeof(char *));
	size_t total_words = 0, word_capacity = 10;

	if (!temp_words) return 0;
	while ((line = get_next_line(fd)) != NULL) {
		char *word = strtok(line, " \n\t");
		while (word) {
			if (total_words >= word_capacity) {
				word_capacity *= 2;
				char **new_words = realloc(temp_words, word_capacity * sizeof(char *));
				if (!new_words) return (0);
				temp_words = new_words;
			}
			temp_words[total_words++] = ft_strdup(word);
			word = strtok(NULL, " \n\t");
		}
		free(line);
	}
	*words = temp_words; 
	return (total_words); 
}

char *get_next_line(int fd)
{
    static char *buffer = NULL;
    char *line = NULL;
    char *temp;

    if (fd < 0 || BUFFER_SIZE <= 0) return NULL;
    (int )buffer = ft_read(fd);
    if (!buffer) return NULL;
    if (ft_strchr(buffer, '\n')) {
        temp = ft_strchr(buffer, '\n');
        *temp = '\0';
        line = ft_strdup(buffer);
        buffer = ft_free(buffer, temp + 1);
    } else {
        line = ft_strdup(buffer);
        free(buffer);
        buffer = NULL;
    }
    return (line);
}

