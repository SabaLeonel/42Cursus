/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:16:13 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/05/29 16:38:15 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_table *table)
{
	if (pthread_mutex_init(&table->m_print, 0)
		|| pthread_mutex_init(&table->m_nb_eat, 0)
		|| pthread_mutex_init(&table->m_dead, 0))
		return (1);
	table->data.m_nb_eat = &table->m_nb_eat;
	table->data.m_print = &table->m_print;
	table->data.m_dead = &table->m_dead;
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
		table->data.philo[i].time_lastmeal = get_time();
		if (pthread_mutex_init(&table->data.philo[i].fork, 0))
			return (1);
		table->data.philo[i].checkfork = 1;
		if (table->data.philo[i].id < table->data.nb_philo)
			table->data.philo[i].fork_r = &table->data.philo[i + 1].fork;
		else
			table->data.philo[i].fork_r = &table->data.philo[0].fork;
		if (pthread_create(&table->data.philo[i].thread,
				NULL, &routine, &(table->data.philo[i])))
			return (1);
	}
	i = -1;
	while (++i < table->data.nb_philo)
	{
		if (pthread_join(&table->data.philo->thread[i], 0))
			return (1);
	}
	return (0);
}

int	init_table(t_table *table, char **av)
{
	if (check_args(av, table))
		return (error("Arguments are not valid"));
	if (init_mutex(table))
		return (error("Init mutex failed"));
	table->data.full_philo = &table->full_philo;
	table->data.dead = &table->dead;
	table->data.start_time = get_time();
	table->data.philo = (t_philo *)malloc(sizeof(t_philo)
			* table->data.nb_philo);
	if (!table->data.philo)
		return (1);
	return (0);
}
