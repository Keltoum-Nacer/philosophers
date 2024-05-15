/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:28:48 by knacer            #+#    #+#             */
/*   Updated: 2024/05/15 20:15:38 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void    print_error()
{
    printf("error, the arguments should be greater than 0 \n");
    exit(1);
}

void    check_input(char **av, t_philo *philo, int ac)
{
    if (is_alpha(av) == 0)
    {
        philo->num_philo = ft_atoi(av[1]);
        if(philo->num_philo < 1 || philo->num_philo > 200)
        {
            printf("error, number of philosophers should be less than 200 and greater than 1\n");
            exit(1);
        }
        philo->time_to_die = ft_atoi(av[2]);
        philo->time_to_eat = ft_atoi(av[3]);
        philo->time_to_sleep = ft_atoi(av[4]);
        if(ac == 6)
            philo->nbr_of_eat = ft_atoi(av[5]);
        else
            philo->nbr_of_eat = -1;
        if(philo->time_to_die <= 0 || philo->time_to_eat <= 0 || philo->time_to_sleep <= 0 )
            print_error();
    }
}

void    init_data(t_philo *philo, int i)
{
            philo->thread_id = i;
            philo->is_eating = 0;
            philo->meals_eaten = 0;
            philo->is_over = 0;
            philo->last_meal = get_current_time();
            philo->start_time = get_current_time();
            philo->l_fork = philo->forks[i];
            if (i == 1)
                philo->r_fork = philo->forks[philo->num_philo];
            else
                philo->r_fork = philo->forks[i - 1];
            
}

void    init_forks(t_philo  *philo)
{
    int i = 1;
    while( i <= philo->num_philo)
    {
        pthread_mutex_init(&philo->forks[i], NULL);
        i++;
    }
}

void    *monitor(void   *arg)
{
    t_philo *philo;

    philo = (t_philo*)arg;
    while(1)
    {
        if(philo->time_to_eat < philo->last_meal && philo->is_eating = 0)
            exit(1);
    }
}

void    *routine(void   *arg)
{
    t_philo *philo;
 
    philo = (t_philo*)arg;
    if(philo->thread_id % 2 == 0)
        ft_usleep(1);
    

        p_think(philo);
        p_sleep(philo);
        p_eat(philo);
        
    return NULL;
}

int main(int ac, char **av)
{
    if (ac == 5 || ac == 6)
    {
        t_philo philo;
        pthread_mutex_t mutex;
        int i;
        
        check_input(av, &philo, ac);
        pthread_mutex_init(&mutex, NULL);
        pthread_create(&philo.monitor, NULL, monitor, (void*)&philo);
        pthread_join(philo.monitor, NULL);
        init_forks(&philo);
        i = 1;
        while(i <= philo.num_philo)
        {
            init_data(&philo, i);
            pthread_create(&philo.threads[i], NULL, routine, (void*)&philo);
            pthread_join(philo.threads[i], NULL);
            i++;
        }  
    }
    else
    printf("error, enter six or seven arguments");
}

