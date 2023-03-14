/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:23:06 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/15 00:16:26 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "mlx.h"

typedef struct s_canvas
{
	void		*img;
	char		*cvs;
	int			x;
	int			y;
	int			pixel_bits;
	int			line_bytes;
	int			endian;
}	t_canvas;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_window
{
	void		*win;
	void		*mlx;
	t_canvas	cvs;
}	t_window;




typedef struct s_game
{
	int			**map;
	t_vector	player_pos;
	t_window	window;
	t_vector	size;
	int			collectible;
	int			coll_count;
	int			players;
	int			exit;
	int			move_count;

	t_canvas	sprites[5];
}	t_game;

enum
{
	EMPTY,
	WALL,
	PLAYER,
	COLLECTIBLE,
	EXIT,
};

enum e_keycode
{
	KEYCODE_A = 0,
	KEYCODE_S = 1,
	KEYCODE_D = 2,
	KEYCODE_F = 3,
	KEYCODE_H = 4,
	KEYCODE_G = 5,
	KEYCODE_Y = 6,
	KEYCODE_X = 7,
	KEYCODE_C = 8,
	KEYCODE_V = 9,
	KEYCODE_RAN = 10,
	KEYCODE_B = 11,
	KEYCODE_Q = 12,
	KEYCODE_W = 13,
	KEYCODE_E = 14,
	KEYCODE_R = 15,
	KEYCODE_Z = 18,
	KEYCODE_T = 17,
	KEYCODE_1 = 18,
	KEYCODE_2 = 19,
	KEYCODE_3 = 20,
	KEYCODE_4 = 21,
	KEYCODE_6 = 22,
	KEYCODE_5 = 23,
	KEYCODE_9 = 25,
	KEYCODE_7 = 26,
	KEYCODE_8 = 28,
	KEYCODE_0 = 29,
	KEYCODE_O = 31,
	KEYCODE_I = 34,
	KEYCODE_L = 37,
	KEYCODE_K = 40,
	KEYCODE_TAB = 49,
	KEYCODE_SPACE = 49,
	KEYCODE_LEFT_ARROW = 123,
	KEYCODE_RIGHT_ARROW = 124,
	KEYCODE_DOWN_ARROW = 125,
	KEYCODE_UP_ARROW = 126,
	KEYCODE_LSHIFT = 257,
	KEYCODE_RSHIFT = 258,
};



#endif