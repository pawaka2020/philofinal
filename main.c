/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2022/06/09 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	start(t_philo *philo)
{
	int	i;

	philo = thread_create(philo);
	death_checker(philo);
	i = -1;
	while (++i < philo->num)
		pthread_join(philo->thread[i], 0);
}

void	philo_one(t_philo *philo)
{
	long	time;

	time = s_to_m();
	printf("%ld 1 is thinking\n", time);
	usleep(philo->death_time * 1000);
	printf("%ld 1 died\n", time + philo->death_time);
}

int	main(int argc, char **argv)
{	
	t_philo	*philo;

	if (check_invalid(argc, argv) == 1)
	{
		printf("Error\n");
		return (1);
	}
	philo = init_threads(argc, argv);
	philo = init_states(philo);
	if (philo->num != 1)
		start(philo);
	else
		philo_one(philo);
	free_malloc(philo);
	return (0);
}
