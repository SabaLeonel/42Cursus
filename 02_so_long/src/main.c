/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:32:25 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/19 19:34:27 by lsaba-qu         ###   ########.fr       */
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

int	main(void)
{
	void	*mlx;
	t_data	img;

	mlx = mlx_init();
	img.img = mlx_new_image(mlx, 1920, 1080);

	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
}
// int	main(int argc, char **argv)
// {
// 	t_game	game;

// 	game.players = 0;
// 	game.exit = 0;
// 	game.coll_count = 0;
// 	game.collectible = 0;
// 	game.move_count = 0;
// 	if (argc != 2)
// 		error("missing map");
// 	parse_map(argv[1], &game);
// 	// printmap(&game);
// 	game.window.mlx = mlx_init();
// 	if (game.window.mlx == NULL)
// 		return (EXIT_FAILURE);
// 	game.window.win = mlx_new_window(game.window.mlx,
// 			96 * game.size.x, 96 * game.size.y, "SO_LONG");
// 	if (game.window.win == NULL)
// 		return (EXIT_FAILURE);
// 	init_sprites(&game);
// 	draw_map(&game);
// 	game.coll_count = 0;
// 	mlx_hook(game.window.win, 2, 0, key_hook, &game);
// 	mlx_loop(game.window.mlx);
// }
