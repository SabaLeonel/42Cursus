/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:35:39 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/05/23 19:13:03 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>

void	*routine(void *arg)
{
	t_state	*data;
	t_philo *philo;
	int		i;

	i = 0;
	philo = (t_philo *)arg;
	data = philo->data;
	// data->philo->time_lastmeal = get_time();
	if (data->philo->id % 2)
		usleep(1500);
	while (!data->philo[i].dead)
	{
		eat(data->philo[i]);
		if (data->philo[i].dead)
			break;
		print_action(&data->philo[i], SLEEP);
		ft_wait(data->tt_sleep, data->philo[i]);
		print_action(&data->philo[i], THINK);
	}
	return (0);
}

int	main(int argc, char **av)
{
	t_state	data;

	data = (t_state){};
	if (argc < 4 || argc > 6)
		error("Invalid number of arguments");
	init_table(&data, av);
	// init_threads(&data);
	return (0);
}