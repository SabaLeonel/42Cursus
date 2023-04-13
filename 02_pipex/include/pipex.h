/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:23:06 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/04/13 18:43:20 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_cmd
{
	int		fd;
	char	*path;
	char	**arg;
}	t_cmd;


void	message(char *msg, int mode);
void	parent_proc(int fd[], char **argv, char **env);
void	parse_cmd(t_cmd *cmd, int fd, char *arg, char **env);
void	child_proc(int fd[], char **argv, char **env);
void	init_path(char *arg, char **env);

#endif