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

int is_dead(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->dead);
    if (philo->data->is_over == 1)
    {
        pthread_mutex_unlock(&philo->data->dead);
        return(1);
    }
    pthread_mutex_unlock(&philo->data->dead);
    return (0);
}
void    print_msg(char  *str, t_philo  *philo)
{
    
    if (is_dead(philo))
        return ;
    pthread_mutex_lock(&philo->data->write);
    printf(str, get_current_time() - philo->data->start_time, philo->thread_id);
    pthread_mutex_unlock(&philo->data->write);
}


void    p_eat(t_philo   *philo)
{
   if (philo->thread_id % 2 == 0)
   {
    pthread_mutex_lock(philo->r_fork);
    print_msg("%zu %d has taken a fork\n", philo);
    pthread_mutex_lock(philo->l_fork);
    print_msg("%zu %d has taken a fork\n", philo);
   }
   else
   {
    pthread_mutex_lock(philo->l_fork);
    print_msg("%zu %d has taken a fork\n", philo);
    pthread_mutex_lock(philo->r_fork);
    print_msg("%zu %d has taken a fork\n", philo);
   } 
    philo->is_eating = 1;
    print_msg("%zu %d is eating\n", philo);
    pthread_mutex_lock(&philo->data->meal);
    philo->last_meal = get_current_time();
    philo->meals_eaten++;
    pthread_mutex_unlock(&philo->data->meal);
    ft_usleep(philo->data->time_to_eat);
    philo->is_eating = 0;
    pthread_mutex_unlock(philo->l_fork);
    pthread_mutex_unlock(philo->r_fork);
}

void    p_sleep(t_philo *philo)
{
    print_msg("%zu %d is sleeping\n", philo);
    ft_usleep(philo->data->time_to_sleep);
}

void    p_think(t_philo *philo)
{
    print_msg("%zu %d is thinking\n", philo);
}