/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:32:25 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/22 19:36:52 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vector	init_map_size(char *path)
{
	t_vector	res;
	int			fd;
	char		buffer[1000];
	int			size;
	int			i;

	res.x = 0;
	res.y = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error("No such file or directory");
	size = read(fd, buffer, 999);
	while (size != 0)
	{
		buffer[size] = 0;
		i = -1;
		while (buffer[++i])
		{
			if (buffer[i] == '\n')
				res.y ++;
		}
		size = read(fd, buffer, 999);
	}
	return (res);
}

void	parse_map(char *path, t_game *game)
{
	int		fd;
	char	*temp;

	check_extension(path);
	game->size = init_map_size(path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error("No such file or directory");
	temp = ft_get_next_line(fd);
	game->size.x = ft_strlen(temp) - 1;

	if (game->size.y < 4 || game->size.x < 4)
		error("Map is too small");
	game->map = ft_allok(game->size.y, sizeof(int *), 1);
	// generate map
	generate_map(game, fd, temp);
	// check min amount
	// check wall
	// check solvable map
	// clean solvable
	
}

// void	printmap(t_game *game)
// {
// 	for(int i = 0; i < game->size.y; i ++)
// 	{
// 		for(int j = 0; j < game->size.x; j ++)
// 		{
// 			printf("%i ",game->map[i][j]);
// 		}
// 		printf("\n");
// 	}
// }


int	main(int argc, char **argv)
{
	t_game	game;

	game.exit = 0;
	game.item = 0;
	game.item_count = 0;
	game.moves = 0;
	game.players = 0;

	if (argc != 2)
		msg_error(argc);
	parse_map(argv[1], &game);
	// printmap(&game);
	return (0);
}

