/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:51:41 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/05/25 19:03:39 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(char **av, t_table *table)
{
	table->data.nb_philo = (int)ft_atoi(av[1]);
	table->data.tt_die = ft_atoi(av[2]);
	table->data.tt_eat = ft_atoi(av[3]);
	table->data.tt_sleep = ft_atoi(av[4]);
	if (av[5])
	{
		table->data.nb_eat = (int)ft_atoi(av[5]);
		if (table->data.nb_eat <= 0)
			return (-1);
	}
	if (table->data.tt_die < 1
		|| table->data.tt_die > 2147483647
		|| table->data.tt_eat < 1
		|| table->data.tt_eat > 2147483647
		|| table->data.tt_sleep < 1
		|| table->data.tt_sleep > 2147483647
		|| table->data.nb_philo < 1
		|| table->data.nb_philo > 2147483647)
		return (-1);
	return (0);
}

/*
** 		check si meurt (diff entre timestamp actuel et timelastmeal > ttdie || == ttdie MORT
** 		Si meurt lock mutex_print
*/
void	isdead(t_philo *philo)
{
	unsigned long long	curr_time;

	curr_time = get_time();
	if (curr_time - philo->time_lastmeal > philo->data.tt_die)
	{
		pthread_mutex_lock(philo->data.mutex_print);
		pthread_mutex_lock(philo->data.mutex_full_philo);
		printf("%llu\t\tPhilo %d is dead\n", curr_time - philo->data.start_time, philo->id);
		exit(0);
	}

}

void isfull(t_philo *philo)
{
	unsigned long long	curr_time;

	curr_time = get_time();
	pthread_mutex_lock(philo->data.mutex_full_philo);
	if (philo->data.full_philo == philo->data.nb_philo);
	{
		pthread_mutex_lock(philo->data.mutex_print);
		printf("%llu\t\tphilos are full\n", curr_time - philo->data.start_time);
		exit (0);
	}
	pthread_mutex_unlock(philo->data.mutex_full_philo);
}

// int	isdead(t_state *data)
// {
// 	int					i;
// 	unsigned long long	curr_time;

// 	i = 0;
// 	while (i < data->nb_philo)
// 	{
// 		curr_time = get_time();
// 		if (data->philo[i].dead
// 			|| curr_time - data->philo[i].time_lastmeal > data->tt_die)
// 		{
// 			print_action(&data->philo[i], DEAD);
// 			data->philo[i].dead = 1;
// 		}
// 		if (data->philo[i].dead)
// 			return (-1);
// 		i ++;
// 	}

// 	return (0);
// }

// int	check_all_eat(t_state *data)
// {
// 	int		i;

// 	i = 0;
// 	while (i < data->nb_philo && data->philo[i].nb_ate
// 		>= data->max_meal && data->max_meal > 0)
// 		i ++;
// 	if (data->nb_philo == i)
// 	{
// 		data->all_dead = 1;
// 		return (-1);
// 	}
// 	return (0);
// }
