/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:52:41 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/28 15:16:54 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int mousecode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (mousecode == ZOOM_IN)
		update_f(data, 0.90);
	if (mousecode == ZOOM_OUT)
		update_f(data, 1.10);
	fractal_render(data);
	return (0);
}
