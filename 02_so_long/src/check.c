/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:31:44 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/22 15:47:23 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extension(char *path)
{
	int len;

	len = ft_strlen(path);
	if (len < 5 || ft_strcmp(&path[len - 4], ".ber"))
		error("invalid file extension");
}