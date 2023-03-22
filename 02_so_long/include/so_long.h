/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:23:06 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/22 19:35:42 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include "hook.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>


typedef struct s_canvas
{
	void	*img;
	char	*addr;
	int		pixel_bits;
	int		line_length;
	int		endian;
}	t_canvas;

typedef struct s_window
{
	void		*mlx;
	void		*win;
}	t_window;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_game
{
	t_vector	size;
	t_vector	playerpos;
	t_window	window;
	int			**map;
	int			item;
	int			item_count;
	int			moves;
	int			exit;
	int			players;
	t_canvas	sprites[5];
}	t_game;

t_vector	init_map_size(char *path);
void		parse_map(char *path, t_game *game);
void		check_extension(char *path);
void		error(char *message);
void		msg_error(int ac);
void		generate_map(t_game *game, int fd, char *temp);
int			check_elements(char c, t_game *game);

enum
{
	EMPTY, //0
	ITEMS, //1
	EXIT, // 2
	PLAYERS, //3
	WALL, // 4
};

#endif