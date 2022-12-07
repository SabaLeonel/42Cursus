/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:15:12 by lsaba-qu          #+#    #+#             */
/*   Updated: 2022/12/07 15:36:14 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *buf)
{
	char *temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

// delete line find et garder tout ce qui se trouve entre le premier \n et la fin de la chaine 
char	*ft_next(char *buffer)
{
	
}

// lire le fichier jusqua \n 
char	*read_file(int fd, char *res)
{
	char	*temp;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	//read la buffersize ensuite join
}

// deja un \n return debut juqua \n si pas de \n dans le toute return tout 
char	*ft_line(char *buffer)
{
	
}

char	*get_next_line(int fd)
{
	static	*buffer;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (0);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}
