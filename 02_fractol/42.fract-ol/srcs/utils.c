/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:10:38 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/01 16:11:47 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	choose_color(int iter, double zr2, double zi2, t_data *data)
{
	double	ratio;

	ratio = ((double)iter + 2 - log(log(zr2 + zi2)) / M_LN2) / 10;
	ratio /= 3.33;
	return (encode_rgb(data, ratio));
}

int	encode_rgb(t_data *data, double ratio)
{
	int	color;

	color = 0;
	if (data->color_r != 0)
		color += (int)(ratio * 255) << 16;
	if (data->color_g != 0)
		color += (int)(ratio * 255) << 8;
	if (data->color_b != 0)
		color += (int)(ratio * 255);
	return (color);
}
