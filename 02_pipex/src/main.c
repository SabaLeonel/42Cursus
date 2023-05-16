/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:35:39 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/05/16 16:24:34 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	checkpath(char *file)
{
	if (file && (ft_strncmp(file, "./", 2) == 0 || file[0] == '/'))
	{
		if ((file[0] == '.' && access(&file[2], F_OK) == 0)
			|| (file[0] == '/' && access(&file[1], F_OK) == 0))
			return (1);
	}
	return (0);
}

char	*get_executable(char *file, char **env)
{
	char	cmd[999];
	char	**path;
	int		i;

	if (checkpath(file) == 1)
		return (file);
	i = -1;
	path = getpath(env);
	if (!file || !path)
		error(-1);
	while (path[++i])
	{
		printf("%s\n", cmd);
		ft_strcpy(cmd, path[i]);
		ft_strcat(cmd, "/");
		ft_strcat(cmd, file);
		if (access(cmd, F_OK) == 0)
		{
			ft_free_pp((void **)path);
			return (ft_strdup(cmd));
		}
	}
	ft_free_pp((void **) path);
	return (0);
}

char	**getpath(char **env)
{
	int		i;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			return (ft_split(env[i] + 5, ':'));
	}
	return (NULL);
}

void	exec(char *cmd, char **env, int input, int output)
{
	char	**args;
	char	*file;
	int		pid;

	args = ft_split(cmd, ' ');
	file = get_executable(args[0], env);
	for (int i = 0 ; args[i]; i++)
		printf("%s\n",args[i]);
	if (!file)
		error(-1);
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
		free((void *)file);
		ft_free_pp((void **)args);
	}
}

int	main(int argc, char **argv, char **env)
{
	int	fd;
	int	_pipe[2];

	if (argc == 5)
	{
		if (pipe(_pipe) == -1)
			error(-1);
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			error(-1);
		exec(argv[2], env, fd, _pipe[1]);
		fd = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY, 0000644);
		if (fd < 0)
			error(-1);
		exec(argv[3], env, _pipe[0], fd);
	}
	else
	{
		ft_putendl_fd("Pipex: Error: Invalid arguments", STDERR_FILENO);
		exit (1);
	}
	return (EXIT_SUCCESS);
}
