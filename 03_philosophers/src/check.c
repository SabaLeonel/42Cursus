/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:51:41 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/05/19 21:52:53 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** 		check si meurt (diff entre timestamp actuel et timelastmeal > ttdie || == ttdie MORT
** 		Si meurt lock mutex_print
*/
int	check_state(t_state *data)
{
	int					i;
	unsigned long long	curr_time;

	i = 0;
	while (i < data->nb_philo)
	{
		curr_time = get_time();
		if (data->philo[i].dead || curr_time - data->philo[i].time_lastmeal > data->tt_die)
		{
			print(data->philo[i], DEAD);
			data->philo[i].dead = 1;
		}
		if (data->philo[i].dead)
			return (1);
		i ++;
	}
	// check all eat
	return (0);
}


int check_all_eat(t_state *data)
{
	(void)data;
	// compare nbeat et nb ate
	return (1);
}