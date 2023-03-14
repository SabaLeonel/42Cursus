/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 07:38:50 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/15 00:18:54 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_canvas	ft_init_image(void *mlx, char *filename)
{
	t_canvas	cvs;

	cvs.img = mlx_xpm_file_to_image(mlx, filename, &cvs.x, &cvs.y);
	cvs.cvs = mlx_get_data_addr(cvs.img,
			&cvs.pixel_bits, &cvs.line_bytes, &cvs.endian);
	return (cvs);
}

void	error(char *message)
{
	if (message)
	{
		ft_putendl_fd("Error", 2);
		ft_putstr_fd("so_long: ", 2);
		ft_putendl_fd(message, 2);
	}
	ft_garbage_collector(0, 1, 1);
}

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


int	check_elements(char c, t_game *game)
{
	if (c == '0')
		return (EMPTY);
	else if (c == '1')
		return (WALL);
	else if (c == 'C' && ++game->collectible)
		return (COLLECTIBLE);
	else if (c == 'E' && ++game->exit)
		return (EXIT);
	else if (c == 'P' && ++game->players)
		return (PLAYER);
	else
		error("invalid caratere");
	return (-1);	
}

void	check_extension(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 5 || ft_strcmp(&path[len -4], ".ber"))
		error("invalid filetype");
}

void	generate_map(t_game *game, int fd, char *temp)
{
    int x;
	int	y ;

	y =0;
	while (temp)
	{
		if ((int)ft_strlen(temp) - 1 != game->size.x) // check si la longeur est la meme entre la premiere ligne et les autres
			error("les lignes sont pas a la meme taille");
		x = -1;
		game->map[y] = ft_allok(game->size.x, sizeof(int), 1);
		while (++x < game->size.x)
		{
			game->map[y][x] = check_elements(temp[x], game);
			if (game->map[y][x] == PLAYER)
			{
				game->player_pos.x = x;
				game->player_pos.y = y;
			}
		}
		y ++;
		temp = ft_get_next_line(fd);
	}
}

void	check_min_amount(t_game *game)
{
	if (game->players != 1)
		error("invalid player amount");
	if (game->exit != 1)
		error("invalid exit amount");
	if (game->collectible < 1)
		error("invalid collectible amount");
}

void check_wall(t_game *game)
{
	int i;

	i = -1;
	while(++i < game->size.x)
	{
		if (game->map[0][i] != WALL)
			error("not a wall");
		if (game->map[game->size.y -1][i] != WALL)
			error("not a wall");
	}
	i = -1;
	while (++i < game->size.y)
	{
		if (game->map[i][0] != WALL)
			error("not a wall");
		if (game->map[i][game->size.x -1] != WALL)
			error("not a wall");
	}
}

void	printmap(t_game *game)
{
	for(int i = 0; i < game->size.y; i ++)
	{
		for(int j = 0; j < game->size.x; j ++)
		{
			printf("%i ",game->map[i][j]);
		}
		printf("\n");
	}
}

void	init_sprites(t_game *game)
{
	game->sprites[WALL] = ft_init_image(game->window.mlx, "sprites/sprite_wall.xpm");
	game->sprites[EXIT] = ft_init_image(game->window.mlx, "sprites/sprite_exit.xpm");
	game->sprites[EMPTY] = ft_init_image(game->window.mlx, "sprites/sprite_empty.xpm");
	game->sprites[PLAYER] = ft_init_image(game->window.mlx, "sprites/sprite_player.xpm");
	game->sprites[COLLECTIBLE] = ft_init_image(game->window.mlx, "sprites/sprite_collectible.xpm");
}

void	check_is_solvable(int x, int y, t_game *game)
{
	if (game->map[y][x] == WALL || game->map[y][x] >=  10)
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

void	draw_map(t_game *game)
{
	int	x;
	int	y;
	mlx_clear_window(game->window.mlx, game->window.win);
	y = -1;
	while (++y < game->size.y)
	{
		x = -1;
		while (++x < game->size.x)
		{
			mlx_put_image_to_window(game->window.mlx, game->window.win,  game->sprites[EMPTY].img, x * 96, y * 96);
			mlx_put_image_to_window(game->window.mlx, game->window.win,  game->sprites[game->map[y][x]].img, x * 96, y * 96);
		}
	}
}

int	key_hook(int key, t_game *game)
{
	t_vector	new_pos;

	new_pos = game->player_pos;
	if (key == KEYCODE_A)
		new_pos.x -= 1;
	else if (key == KEYCODE_S)
		new_pos.y += 1;
	else if (key == KEYCODE_D)
		new_pos.x += 1;
	else if (key == KEYCODE_W)
		new_pos.y -= 1;
	else
		return (0);
	if (game->map[new_pos.y][new_pos.x] == WALL
		|| (game->map[new_pos.y][new_pos.x] == EXIT && game->coll_count != game->collectible))
		return (0);
	game->map[game->player_pos.y][game->player_pos.x] = 0;
	if (game->map[new_pos.y][new_pos.x] == COLLECTIBLE)
		game->coll_count++;
	if (game->map[new_pos.y][new_pos.x] == EXIT)
	{
		printf("zyou won\n");
		game->player_pos = new_pos;
		draw_map(game);
		return (0);
	}
	game->map[new_pos.y][new_pos.x] = PLAYER;
	game->player_pos = new_pos;
	draw_map(game);
	game->move_count++;
	printf("you did %i steps\n", game->move_count);
	return (0);
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
	printmap(&game);
	game.window.mlx = mlx_init();
	if (game.window.mlx == NULL)
		return (EXIT_FAILURE);
	game.window.win = mlx_new_window(game.window.mlx, 96 * game.size.x, 96 * game.size.y, "SO_LONG");
	if (game.window.win == NULL)
		return (EXIT_FAILURE);
	init_sprites(&game);
	draw_map(&game);
	game.coll_count = 0;
	mlx_hook(game.window.win, 2, 0, key_hook, &game);
	mlx_loop(game.window.mlx);
}
