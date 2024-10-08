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

int ft_counter(int i)
{
	i = 0;
	while (i != '\0')
	{
		i++;
	}
	return(i);
}

char *get_next_line(int fd)
{
	int rl;
	int i;

	ft_counter(i);
	if (!fd || fd = "\0")
		return (NULL);

	while (rl != '\0')
	{
		if (i = " ")
			write(1, "\n", 1);
		else if (rl = '\0')
			return(0);
	}
	return  (rl);
}
