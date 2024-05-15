/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:29:04 by knacer            #+#    #+#             */
/*   Updated: 2024/05/15 15:54:15 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/time.h>


typedef struct s_philo
{
  int   num_philo;
  int   is_over;
  size_t time_to_die;
  size_t time_to_eat;
  size_t time_to_sleep;
  int        nbr_of_eat;
  int         is_eating;
  int         meals_eaten;
  size_t      last_meal;
  size_t      start_time; 
  pthread_t threads[200];
  pthread_t   monitor;
  int       thread_id;
  pthread_mutex_t forks[200];
  pthread_mutex_t r_fork;
  pthread_mutex_t l_fork;
  size_t  now;
}t_philo;

int   is_alpha(char **av);
int	ft_atoi(const char *str);
size_t	get_current_time(void);
int	ft_usleep(size_t milli_sec);
void    p_think(t_philo *philo);
void    p_sleep(t_philo *philo);
void    p_eat(t_philo   *philo);


#endif
