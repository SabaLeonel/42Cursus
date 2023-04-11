/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:35:39 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/04/11 18:19:23 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	// char *arg[2] = {"-l", NULL};
	// if (argc != 5)
	// 	print("Invalid arguments", 1);
	 (void)argv;
	 (void)env;
	 (void)argc;
	// int fd = open("file.txt", O_WRONLY | O_CREAT ,777);
	// int pid;
	// dup2(fd, 1);
	//  pid = fork();
	// if (pid == 0)
	//  	execve("/bin/ls", arg, env);
	// if (pid != 0)
	// {
	// 	waitpid(pid, NULL, 0);
	// 	print("parent", 1);
	// }

	int fd[2];
	pipe(fd);
	int x = 41;
	int y = 0;
	int pid = fork();
	if (pid == 0)
	{
		x++;
		write(fd[1], &x, sizeof(int));
	}
	if (pid != 0)
	{
		//waitpid(pid, NULL, 0);
		read(fd[0], &y, sizeof(int));
		printf("%d | %d\n", y, x);
	}
	return (0);
}
