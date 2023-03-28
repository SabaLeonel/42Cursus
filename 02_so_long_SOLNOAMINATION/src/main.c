/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 07:38:50 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/22 17:30:24 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vector	map_size(char *path)
{
	int			fd;
	t_vector	res;
	char		buffer[1000];
	int			size;
	int			i;

	res.y = 0;
	res.x = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error("cannot open file");
	size = read(fd, buffer, 999);
	while (size)
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

void	check_is_solvable(int x, int y, t_game *game)
{
	if (game->map[y][x] == WALL || game->map[y][x] >= 10)
		return ;
	if (game->map[y][x] == COLLECTIBLE)
		game->coll_count++;
	if (game->map[y][x] == EXIT)
		game->exit++;
	game->map[y][x] += 10;
	check_is_solvable(x + 1, y, game);
	check_is_solvable(x - 1, y, game);
	check_is_solvable(x, y + 1, game);
	check_is_solvable(x, y - 1, game);
}

void	clean_solvable(t_game *game)
{
	int	i;
	int	j;

	if (game->coll_count != game->collectible)
		error("cannot reach all collectibles");
	if (game->exit != 1)
		error("cannot reach the exit");
	i = -1;
	while (++i < game->size.y)
	{
		j = -1;
		while (++j < game->size.x)
		{
			if (game->map[i][j] >= 10)
				game->map[i][j] -= 10;
		}
	}
}

void	parse_map(char *path, t_game *game)
{
	int		fd;
	char	*temp;

	check_extension(path);
	game->size = map_size(path);
	if (game->size.y < 4)
		error("la map elle est trop petite frere");
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error("cannot open file");
	temp = ft_get_next_line(fd);
	game->size.x = ft_strlen(temp) - 1;
	if (game->size.x < 4)
		error("la map elle est trop petite frere");
	game->map = ft_allok(game->size.y, sizeof(int *), 1);
	generate_map(game, fd, temp);
	check_min_amount(game);
	check_wall(game);
	game->exit = 0;
	check_is_solvable(game->player_pos.x, game->player_pos.y, game);
	clean_solvable(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.players = 0;
	game.exit = 0;
	game.coll_count = 0;
	game.collectible = 0;
	game.move_count = 0;
	if (argc != 2)
		error("missing map");
	parse_map(argv[1], &game);
	// printmap(&game);
	game.window.mlx = mlx_init();
	if (game.window.mlx == NULL)
		return (EXIT_FAILURE);
	game.window.win = mlx_new_window(game.window.mlx,
			96 * game.size.x, 96 * game.size.y, "SO_LONG");
	if (game.window.win == NULL)
		return (EXIT_FAILURE);
	init_sprites(&game);
	draw_map(&game);
	game.coll_count = 0;
	mlx_hook(game.window.win, 2, 0, key_hook, &game);
	mlx_loop(game.window.mlx);
}
