/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:42:07 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/04/14 12:00:42 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parse_env(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
		{
			return (ft_split(env[i] + 5, ':'));
		}
	}
	return (NULL);
}

char *parse_path(char *cmd, char *path)
{
	int	i;
	char *newpath;

	newpath = ft_calloc(ft_strlen(path)+ 2, sizeof(char *));
	if (!newpath)
	{
		free(newpath);
		return (NULL);
	}
	ft_memcpy(newpath, path, ft_strlen(path));
	newpath[ft_strlen(path)] = '/';
	newpath = ft_add_stock(newpath, cmd);
	return (newpath);
}

void init_path(char *cmd, char **env)
{
	char	**paths;
	int		i;

	i = 0;
	paths = parse_env(env);
	if (!paths)
		message("Can't split env",1);
	while (paths[i])
	{
		paths[i] = parse_path(paths[i], cmd);
		if (!paths[i])
		{
			free_pp(paths);
			message("Can't parse path",1);
		}
		
		i ++;
	}
}
