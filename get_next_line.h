/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:57:25 by marvin            #+#    #+#             */
/*   Updated: 2024/10/08 09:57:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h> 
# include <sys/types.h>
# include <sys/uio.h>

char	*get_next_line(int fd);
int		ft_read(int fd);
char	*ft_free(char *buffer, char *buf);
size_t	ft_word(int fd, char ***words);


char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);



#endif