/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:35:39 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/04/27 19:38:15 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_executable(char *file, char **env)
{
	// char	*newpath = "TEST";

	(void) env;
	printf("file : %s\n", file);
	// if file start with / or ./ check if exist and return
	// 		/bin/ls 
	// 		./pipex
	 if (!access(file, F_OK))
		perror("Pipex: Error: ");
	
	/*
	steps:
		
		get PATH var from env
		split path ':'
		check in all paths if paths[i] + file exist
		
	*/
	return (ft_strdup(file));
}

void	exec(char *cmd, char **env, int input, int output)
{
	char	**args;
	char	*file;
	int		pid;

	args = ft_split(cmd, ' ');
	file = get_executable(args[0], env);
	// printf("%s\n", file);
	pid = fork();
	if (pid == 0)
	{
		dup2(input, STDIN_FILENO);
		dup2(output, STDOUT_FILENO);
		execve(file, args, env);
	}
	else
	{
		waitpid(pid, NULL, 0);
		close(input);
		close(output);
	}
}

int	error(void)
{
	perror("Pipex: Error: ");
	return (EXIT_FAILURE);
}


int	main(int argc, char **argv, char **env)
{
	int	fd;
	int	_pipe[2];

	if (argc == 5)
	{
		if (pipe(_pipe) == -1)
			error();
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			error();
		exec(argv[2], env, fd, _pipe[1]);
		fd = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY, 0000644);
		if (fd < 0)
			error();
		exec(argv[3], env, _pipe[0], fd);
	}
	else
	{
		ft_putendl_fd("Pipex: Error: Invalid arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
