/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:51:27 by knacer            #+#    #+#             */
/*   Updated: 2024/05/31 15:51:32 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_is_dead(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->num_philo)
	{
		pthread_mutex_lock(&philo->data->meal);
		if (get_current_time() - philo[i].last_meal >= philo->data->time_to_die)
		{
			pthread_mutex_unlock(&philo->data->meal);
			pthread_mutex_lock(&philo->data->dead);
			philo->data->is_over = 1;
			pthread_mutex_unlock(&philo->data->dead);
			pthread_mutex_lock(&philo->data->write);
			printf("%zu %d is dead\n", get_current_time()
				- philo->data->start_time, philo[i].thread_id);
			pthread_mutex_unlock(&philo->data->write);
			return (1);
		}
		pthread_mutex_unlock(&philo->data->meal);
		i++;
	}
	return (0);
}

int	they_ate(t_philo *philo)
{
	int	i;
	int	nbr_of_eat;

	if (philo->data->nbr_of_meals == -1)
		return (0);
	i = 0;
	nbr_of_eat = 0;
	while (i < philo->data->num_philo)
	{
		pthread_mutex_lock(&philo->data->meal);
		if (philo[i].meals_eaten >= philo->data->nbr_of_meals)
			nbr_of_eat++;
		pthread_mutex_unlock(&philo->data->meal);
		i++;
	}
	if (nbr_of_eat == philo->data->num_philo)
	{
		pthread_mutex_lock(&philo->data->dead);
		philo->data->is_over = 1;
		pthread_mutex_unlock(&philo->data->dead);
		return (1);
	}
	return (0);
}
