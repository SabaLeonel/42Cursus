/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:35:39 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/04/12 16:03:11 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



void	parent_proc(int fd[], char **argv, char **env)
{
	t_cmd	cmd;

	dup2(fd[0], 1);
	close(fd[0]);
	close(fd[1]);
}

void	child_proc(int fd[], char **argv, char **env)
{
	(void) fd;
	(void) argv;
	(void) env;

	dup2(fd[1], 1);
	close(fd[0]);
	close(fd[1]);
	execve("/bin/ls", "-la", NULL);
}

int	main(int argc, char **argv, char **env)
{
	int	fd[2];
	int	pid;

	if (argc != 5)
		message("Invalid arguments", 1);
	
	if (pipe(fd) == -1)
		message("An error occured when opening the pipe", 1);
	pid = fork();
	if (pid < 0)
		message("An error occured when using fork", 1);
	if (pid == 0)
		child_proc(fd, argv, env);
	else
		parent_proc(fd, argv, env);
	
	// if (pipe(fd))
	// 	printf("Hello\n");
	// char *arg[2] = {"-l", NULL};
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

	// int fd[2];
	// pipe(fd);
	// int x = 41;
	// int y = 0;
	// int pid = fork();
	// if (pid == 0)
	// {
	// 	x++;
	// 	write(fd[1], &x, sizeof(int));
	// }
	// if (pid != 0)
	// {
	// 	waitpid(pid, NULL, 0);
	// 	read(fd[0], &y, sizeof(int));
	// 	printf("%d | %d\n", y, x);
	// }
	close(fd[0]);
	close(fd[1]);
	return (0);
}
