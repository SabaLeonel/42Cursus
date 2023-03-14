/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:27:34 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/30 14:44:13 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		fractol_exit(data);
	if (keycode == ARROW_UP)
		move_f(data, 0, 15);
	if (keycode == ARROW_DOWN)
		move_f(data, 0, -15);
	if (keycode == ARROW_LEFT)
		move_f(data, -15, 0);
	if (keycode == ARROW_RIGHT)
		move_f(data, 15, 0);
	if (keycode == PLUS)
		change_input(data, 0.001);
	if (keycode == MINUS)
		change_input(data, -0.001);
	if (keycode == RED || keycode == GREEN || keycode == BLUE
		|| keycode == YELLOW || keycode == CYAN || keycode == PURPLE)
		param_color(data, keycode);
	if (keycode == RESET)
		reset(data);
	fractal_render(data);
	return (0);
}
