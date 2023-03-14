/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:19:14 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/29 17:55:22 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "proto.h"
# include "hook.h"
# include "error.h"
# include "libft.h"
# include "mlx.h"
# include <math.h>

# define COLOR_MAX_I 0x000000
# define MAX_I 42
# define FRACTAL_TYPE_MANDELBROT 1
# define FRACTAL_TYPE_JULIA 2
# define FRACTAL_TYPE_BURNING 3
# define WIDTH 1000
# define HEIGHT 1000

#endif