/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:16:13 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/06/06 17:18:06 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_table *table)
{
	if (pthread_mutex_init(&table->m_print, 0)
		|| pthread_mutex_init(&table->m_nb_eat, 0)
		|| pthread_mutex_init(&table->m_dead, 0))
		return (1);
	table->data.m_eat = &table->m_nb_eat;
	table->data.m_print = &table->m_print;
	table->data.m_dead = &table->m_dead;
	return (0);
}

// void	check_philo(t_state *data)
// {
// 	int				i;
// 	int				is_finish;
// 	long long int	curr_time;	

// 	is_finish = 0;
// 	while (is_finish)
// 	{
// 		i = 0;
// 		while (i < data->nb_philo)
// 		{
// 			if (data->philo[i].dead)
// 			{
// 				curr_time = get_time();
// 				printf("%llu\t\tPhilo %d is dead\n",
// 					curr_time - data->start_time, data->philo[i].id);
// 				is_finish = 1;
// 				i = 0;
// 				while (i < data->nb_philo)
// 				{
// 					pthread_mutex_lock(&data->philo[i].m_dead);
// 					data->philo[i++].dead = 1;
// 					pthread_mutex_unlock(&data->philo[i].m_dead);
// 				}
// 			}
// 			i++;
// 		}
// 	}
// }

int	solo_philo(t_table *table)
{
	unsigned long long	c;

	c = get_time();
	printf("%llu\t\t1 is thinking\n", c - table->data.start_time);
	printf("%llu\t\t1 died\n", c - table->data.start_time);
	return (0);
}

int	init_philo(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->data.nb_philo)
	{
		table->data.philo[i].data = table->data;
		table->data.philo[i].id = i + 1;
		table->data.philo[i].dead = 0;
		table->data.philo[i].time_lastmeal = get_time();
		pthread_mutex_init(&table->data.philo[i].m_dead, 0);
		if (pthread_mutex_init(&table->data.philo[i].fork, 0))
			return (1);
		table->data.philo[i].checkfork = 1;
		if (table->data.philo[i].id < table->data.nb_philo)
			table->data.philo[i].fork_r = &table->data.philo[i + 1].fork;
		else
			table->data.philo[i].fork_r = &table->data.philo[0].fork;
		// if (pthread_create(&table->data.philo[i].thread,
		// 		0, &routine, &(table->data.philo[i])))
			// return (1);
	}
	
	i = -1;
	while (++i < table->data.nb_philo)
		pthread_create(&table->data.philo[i].thread,
				0, &routine, &(table->data.philo[i]));
	join_threads(&table->data);
	return (0);
}

int	init_table(t_table *table, char **av)
{
	if (check_args(av, table))
		return (1);
	if (init_mutex(table))
		return (error("Init mutex failed"));
	table->data.full_philo = &table->full_philo;
	table->data.dead = &table->dead;
	table->data.start_time = get_time();
	table->data.value = 1;
	table->data.philo = (t_philo *)malloc(sizeof(t_philo)
			* table->data.nb_philo);
	if (!table->data.philo)
		return (1);
	// if (table->data.nb_philo == 1)
	// 	return (solo_philo(table));
	return (0);
}
