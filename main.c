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

#include"philo.h"


void    *routine(void *arg)
{
    t_philo *philo;
    int death;

    philo = (t_philo *)arg;
    if (philo->data->num_philo == 1)
    {
        print_msg("%zu %d has taken a fork\n", philo);
        ft_usleep(philo->data->time_to_die);
        return (NULL);
    }
    if (philo->thread_id % 2 == 0)
        ft_usleep(100);
    // pthread_mutex_lock(&philo->data->dead);
    // death = philo->data->is_over;
    // pthread_mutex_unlock(&philo->data->dead);
        //printf("--------->hey %d\n", death);
    philo->last_meal = get_current_time();
    while (!is_dead(philo))
    {
        p_eat(philo);
        p_sleep(philo);
        p_think(philo);
    }
    return (arg);
}

void    monitor(void *arg)
{
    t_philo *philo;
    int i;
    long    current_time;

    philo = (t_philo *)arg;
    //ft_usleep(100);
    while(1)
    {
        //ft_usleep(10);
    
        if(philo_is_dead(philo) || they_ate(philo))
            break;
    }
}

int main(int ac , char **av)
{
    if (ac == 5 || ac == 6)
    {
        t_philo philos[200];
        t_data  sh_data;
        int i;

        check_input(ac, av, &sh_data);
        init_locks(&sh_data, philos);
        init_data(philos, &sh_data);
        i = 0;
        sh_data.start_time = get_current_time();
        while (i < philos->data->num_philo)
        { 
            pthread_create(&philos[i].thread, NULL, &routine, &philos[i]);
            i++;
        }
        monitor(philos);
        i = 0;
        while(i < philos->data->num_philo)
        {
            pthread_join(philos[i].thread, NULL);
            i++;
        }
    
    }
    else
        printf("error, enter five or six arguments\n");
}
