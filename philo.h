/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:50:54 by knacer            #+#    #+#             */
/*   Updated: 2024/06/05 10:50:56 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/time.h>

typedef struct s_data{

  int   is_over;
  size_t      start_time; 
  pthread_mutex_t meal;
  pthread_mutex_t dead;
  pthread_mutex_t write;
  pthread_mutex_t forks[200];
  int   num_philo;
  size_t time_to_die;
  size_t time_to_eat;
  size_t time_to_sleep;
  pthread_t   monitor;
  int        nbr_of_meals;
  
}t_data;

typedef struct s_philo
{
  
  int         is_eating;
  int         meals_eaten;
  size_t      last_meal;
  pthread_t thread;
  int       thread_id;
  pthread_mutex_t *l_fork;
  pthread_mutex_t *r_fork;
  t_data  *data;
}t_philo;

int   is_alpha(char **av);
int	ft_atoi(const char *str);
void    check_input(int ac, char **av, t_data *manager);
void    init_locks(t_data *manager, t_philo *philos);
void    print_error(int i);
size_t	get_current_time(void);
int	ft_usleep(size_t milli_sec);
void    init_data(t_philo *philo, t_data *manager);
void    p_eat(t_philo  *philo);
void    p_sleep(t_philo *philo);
void    p_think(t_philo *philo);
int   philo_is_dead(t_philo *philo);
int is_dead(t_philo *philo);
void    print_msg(char  *str, t_philo  *philo);
int they_ate(t_philo *philo);

#endif
