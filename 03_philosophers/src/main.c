/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:35:39 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/05/11 17:15:06 by lsaba-qu         ###   ########.fr       */
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
	t_philo t1;
	// t_share	maine_share;
	t1.id = 5;
	(void)argv;

	if (argc < 5 || argc > 6)
		error("Invalid number of arguments");
	
	init_table(&maine_share);
	pthread_create(&t1.thread, NULL, &routine, &t1);
	pthread_join(t1.thread, NULL);	
	return 0;
}


/*
** int bigsleep(usleep )
** {
** 	while
** 	usleep(5);
** }
*/
