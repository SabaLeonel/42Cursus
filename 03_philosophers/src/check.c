/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:51:41 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/05/19 12:39:55 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_state(t_state *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (data->philo[i].time_lastmeal -  get_time() < 
		printf("Hello\n");
		i ++;
	}
		// check si meurt (diff entre timestamp actuel et timelastmeal > ttdie || == ttdie MORT
		// Si meurt lock mutex_print
	// check all eat
}


int check_all_eat(t_state *data)
{
	(void)data;
	// compare nbeat et nb ate
	return (1);
}