/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2022/06/09 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <semaphore.h>

enum e_status{ eating, sleeping, thinking, forking};

typedef struct s_philo	t_philo;

typedef struct s_info
{
	enum e_status	state;
	int				id;
	int				times_eat;
	int				left;
	int				right;
	long			death_timer;
	t_philo			*ptr;
}	t_info;

typedef struct s_philo
{
	int				num;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				eat_cycle;
	int				dead;
	int				eaten;
	pthread_t		*thread;
	pthread_mutex_t	*fork;
	pthread_mutex_t	miniphone;
	t_info			*info;
}	t_philo;

int		main(int argc, char **argv);
int		check_invalid(int argc, char **argv);
int		ft_atoi(const char *str);
int		even_num(int num);
int		odd_num(int num);
void	death_checker(t_philo *philo);
void	eat_to_sleep(t_info *info);
void	free_malloc(t_philo *philo);
void	ft_usleep(int sleep, t_philo *philo);
void	*routine(void *arg);
void	think_to_eat(t_info *info);
void	print_log(t_info *info);
long	s_to_m(void);
t_philo	*thread_create(t_philo *philo);
t_philo	*init_threads(int argc, char **argv);
t_philo	*init_states(t_philo *philo);

#endif