/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:22:05 by lsaba-qu          #+#    #+#             */
/*   Updated: 2022/12/02 21:01:13 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define FT_PRINTF_H

# include <stdlib.h> /* To use 'malloc', 'free' function */
# include <fcntl.h> /* To use 'read' function */
# include <unistd.h> /* To use 'write' function */
# include <limits.h> /* To use 'OPEN_MAX' defined macro */

char	*get_next_line(int fd);
/* Libft functions */
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);

/* Read 'buffer' and attach it to 'store' */
int	read_buffer(int fd, char **store);
/* Split 'store' by newline and save it in 'line' and 'store' */
void	split_store(char **store, char **line);

#endif
