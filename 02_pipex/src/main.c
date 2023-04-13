/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:35:39 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/04/13 18:41:05 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	parse_cmd(t_cmd *cmd, int fd, char *arg, char **env)
{
	cmd->fd = fd;
	cmd->arg = ft_split(env, ' ');
	cmd->path = init_path(arg[0], env);
}

void	parent_proc(int fd[], char **argv, char **env)
{
	t_cmd	cmd;

	ft_bzero(&cmd, sizeof(t_cmd));
	
	parse_cmd(&cmd, 0, argv[4], env);
	
	cmd.fd = open(argv[4], O_WRONLY | O_CREAT ,777);
	if (cmd.fd == -1)
		message("Can't open file", 1);
	//fd[0] parent process
	dup2(cmd.fd, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	
	close(fd[0]);
	close(fd[1]);
}


void	child_proc(int fd[], char **argv, char **env)
{
	t_cmd cmd;

	ft_bzero(&cmd, sizeof(t_cmd));
	parse_cmd(&cmd, 0, argv[2], env);
	cmd.fd = open(argv[1], O_RDONLY);
	if (cmd.fd == -1)
		message("Can't open file", 1);
	//fd[1] child process
	dup2(fd[1], STDOUT_FILENO);
	dup2(cmd.fd, STDIN_FILENO);
	close(fd[0]);
	close(cmd.fd);
	// execve("/bin/ls", argv, NULL);
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
	if (pid == -1)
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
