/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:16:13 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/05/16 17:44:40 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		init_mutex(t_state *data)
{
	// boucle pour fork mutex_init
	// p_thread_mutex_init for print;

	
}


void	init_philo(t_state *data)
{
	int	i;

	i = -1;
	//id philo start with 1
	//boucle x nb philo
	while (++i < data->nb_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].fork_left_id = data->philo[i].id;
		if (data->philo[i].id == 1)
			data->philo[i].fork_right_id = data->nb_eat;
		else
			data->philo[i].fork_right_id = data->philo[i].id - 1;
	}
	// leftid = id_phil
	// right = id - 1 sauf premier
}

void	init_table(t_state *data, char **av)
{
	memset(&data,0, sizeof(t_state));
	data->nb_philo = ft_atoi(av[1]);
	data->tt_die = ft_atoi(av[2]);
	data->tt_eat = ft_atoi(av[3]);
	data->tt_sleep = ft_atoi(av[4]);
	if (av[5])
		data->nb_eat = ft_atoi(av[5]);
	if (data->tt_die < 1 || data->tt_eat < 1 || data->tt_sleep < 1 || data->nb_philo < 2)
		error("Wrong arguments");
	data->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->fork)
		error("Malloc fork failed");
	if (init_mutex(data) == 0)
		error("Init mutex failed");
	init_philo(data);
}

void	init_threads(t_state *data)
{
	// faire boucle 1 thread par philo
	int	i;

	i = 0;
	while (data->philo[i].id)
	{
		if (pthread_create(&data->philo[i].thread, NULL, &routine, &data->philo[i]))
			error("Failed to create a thread");
		i++;
	}
	check_state(data);
}