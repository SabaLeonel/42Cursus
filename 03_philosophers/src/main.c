/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:35:39 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/05/19 21:31:12 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>

void	*routine(t_philo *philo)
{
	t_state	*data;
	int		i;

	i = 0;
	data = philo->data;
	data->philo->time_lastmeal = get_time();
	if (data->philo->id % 2)
		usleep(1500);
	while (!data->philo[i]->dead)
	{
		eat(&data->philo[i]);
		
		// printf("philo think %i\n", philo->id);
		// sleep(1);
		// printf("philo eat %i\n", philo->id);
		// sleep(1);
		// printf("philo sleep %i\n", philo->id);
		sleep(1);
	}
	return (0);
}

int	main(int argc, char **av)
{
	t_state	data;

	data = (t_state){};
	data.start_time = get_time();
	if (argc < 4 || argc > 6)
		error("Invalid number of arguments");
	init_table(&data, av);
	// init_threads(&data);
	return (0);
}