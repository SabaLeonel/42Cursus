/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:29:47 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/05/11 15:30:47 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	signe;

	i = 0;
	res = 0;
	signe = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i ++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i ++;
	}
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + str[i] - '0';
		i ++;
	}
	return (res * signe);
}
