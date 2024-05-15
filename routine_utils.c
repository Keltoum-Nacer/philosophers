/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:32:57 by knacer            #+#    #+#             */
/*   Updated: 2024/05/15 20:12:29 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void    p_think(t_philo *philo)
{
    printf("%zu %d is thinking\n", get_current_time() - philo->start_time, philo->thread_id);
}

void    p_sleep(t_philo *philo)
{
    ft_usleep(philo->time_to_sleep);
    printf("%zu %d is sleeping\n", get_current_time()  - philo->start_time, philo->thread_id);
}

void    p_eat(t_philo   *philo)
{
    pthread_mutex_lock(&philo->l_fork);
    printf("%d has taken a fork\n", philo->thread_id);
    pthread_mutex_lock(&philo->r_fork);
    printf("%d has taken a fork\n", philo->thread_id);
    ft_usleep(philo->time_to_eat);
    philo->last_meal = get_current_time();
    philo->is_eating = 1;
    printf("%zu %d is eating\n", get_current_time() - philo->start_time, philo->thread_id);
    pthread_mutex_unlock(&philo->l_fork);
    pthread_mutex_unlock(&philo->r_fork);
}