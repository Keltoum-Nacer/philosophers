/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:20:13 by knacer            #+#    #+#             */
/*   Updated: 2024/05/29 16:20:15 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void    check_input(int ac, char **av, t_data *sh_data)
{
     if (is_alpha(av) == 0)
    {
        sh_data->num_philo = ft_atoi(av[1]);
        if(sh_data->num_philo < 1 || sh_data->num_philo > 200)
            print_error(1);
        sh_data->time_to_die = ft_atoi(av[2]);
        sh_data->time_to_eat = ft_atoi(av[3]);
        sh_data->time_to_sleep = ft_atoi(av[4]);
        if(ac == 6)
            sh_data->nbr_of_meals = ft_atoi(av[5]);
        else
            sh_data->nbr_of_meals = -1;
        if(sh_data->time_to_die <= 0 || sh_data->time_to_eat <= 0 || sh_data->time_to_sleep <= 0 )
            print_error(0);
    }
}

void    init_data(t_philo *philo, t_data *sh_data)
{
    int i;

    i  = 0;
    
    while(i < sh_data->num_philo)
    {
        philo[i].thread_id = i + 1;
        philo[i].meals_eaten = 0;
        philo[i].is_eating = 0;
        philo[i].last_meal = get_current_time();
        philo[i].l_fork = &sh_data->forks[i];
        
        if(i == sh_data->num_philo - 1)
            philo[i].r_fork = &sh_data->forks[0];
        else
            philo[i].r_fork = &sh_data->forks[i + 1];
        philo[i].data = sh_data;
        i++;
    }
   
}

void    init_locks(t_data *sh_data, t_philo *philos)
{
    int i;

    i = 0;
    
    while (i < sh_data->num_philo)
    {
        pthread_mutex_init(&sh_data->forks[i], NULL);
        i++;
    }
    //sh_data->start_time = get_current_time();
    sh_data->is_over = 0;
    pthread_mutex_init(&sh_data->dead, NULL);
    pthread_mutex_init(&sh_data->meal, NULL);
    pthread_mutex_init(&sh_data->write, NULL);
}