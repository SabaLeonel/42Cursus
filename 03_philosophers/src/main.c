/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:35:39 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/05/16 14:46:36 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>


void	*routine(void *t)
{
	t_philo *philo;
	philo = (t_philo *)t;
	
	while (1)
	{
		printf("philo think %i\n", philo->id);
		sleep(1);
		printf("philo eat %i\n", philo->id);
		sleep(1);
		printf("philo sleep %i\n", philo->id);
		sleep(1);
	}
	return (0);
}



int	main(int argc, char **argv)
{
	t_state *data;

	if (argc < 5 || argc > 6)
		error("Invalid number of arguments");
	data = (t_state *)malloc(sizeof(t_state));	
	init_table(data);
	init_threads(data);
	// pthread_create(&data->philo.thread, NULL, &routine, &data);
	// pthread_join(t1.thread, NULL);	
	return 0;
}


/*
** int bigsleep(usleep )
** {
** 	while
** 	usleep(5);
** }
*/
