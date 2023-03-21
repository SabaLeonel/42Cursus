/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:32:25 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/21 19:14:11 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_game {
	void *mlx;
	void *mlx_win;
	t_data img;
	t_data sprite;
	int x;
	int y;
} 	t_game;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	render_frame(t_game *game);
int mouse_move(int x, int y, t_game *game);

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	for (int i = 0; i < 500; i++)
		my_mlx_pixel_put(&img, i, i, 0x00FF0000);
	int x = 0;
	int y = 0;
	t_data sprite;
	
	sprite.img = mlx_xpm_file_to_image(mlx, "src/sprite_collectible.xpm", &x, &y);
	if (sprite.img == NULL)
		printf("failed to load image .xpm\n");
	sprite.addr = mlx_get_data_addr(sprite.img,
			&sprite.bits_per_pixel, &sprite.line_length, &sprite.endian);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	for (int i = 0; i < 10; i ++)
		mlx_put_image_to_window(mlx, mlx_win, sprite.img, i * 96 , i);

	t_game game;

	game.mlx = mlx;
	game.mlx_win = mlx_win;
	game.img = img;
	game.sprite = sprite;
	
	mlx_hook(game.mlx_win, 6, 0, mouse_move, &game);
	
	mlx_loop_hook(mlx, render_frame, &game);
	printf("hello\n");
	mlx_loop(mlx);
	return (0);
}

// function to render game world to screen
int	render_frame(t_game *game)
{
	// my_mlx_pixel_put(&game->img, 500, 500, 0x00FF0000);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.img, game->x , game->y);
	
	return (0);
}

// function to get input
int mouse_move(int x, int y, t_game *game)
{
	game->x = x;
	game->y = y;
	return (0);
}

