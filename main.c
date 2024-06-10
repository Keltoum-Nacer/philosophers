/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:50:36 by knacer            #+#    #+#             */
/*   Updated: 2024/06/05 10:50:38 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_locks(t_data *sh_data)
{
	int	i;

	i = 0;
	while (i < sh_data->num_philo)
	{
		pthread_mutex_destroy(&sh_data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&sh_data->meal);
	pthread_mutex_destroy(&sh_data->dead);
	pthread_mutex_destroy(&sh_data->write);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		death;

	philo = (t_philo *)arg;
	if (philo->data->num_philo == 1)
	{
		print_msg("%zu %d has taken a fork\n", philo);
        ft_usleep(philo->data->time_to_die);
		return (NULL);
	}
	if (philo->thread_id % 2 == 0)
		ft_usleep(10);
	while (!is_dead(philo))
	{
		p_eat(philo);
		p_sleep(philo);
		p_think(philo);
        ft_usleep(10);
	}
	return (arg);
}

void	monitor(void *arg)
{
	t_philo	*philo;
	int		i;
	long	current_time;

	philo = (t_philo *)arg;
    //ft_usleep(10);
	while (1)
	{
		if (philo_is_dead(philo) || they_ate(philo))
			break ;
	}
}

int	main(int ac, char **av)
{
	t_philo	philos[200];
	t_data	sh_data;
	int		i;

	if (ac == 5 || ac == 6)
	{
		check_input(ac, av, &sh_data);
		init_locks(&sh_data, philos);
		init_data(philos, &sh_data);
		i = 0;
		while (i < philos->data->num_philo)
		{
			pthread_create(&philos[i].thread, NULL, &routine, &philos[i]);
			i++;
		}
		monitor(philos);
		i = 0;
		while (i < philos->data->num_philo)
			pthread_join(philos[i++].thread, NULL);
		destroy_locks(&sh_data);
	}
	else
		printf("error, enter five or six arguments\n");
}
