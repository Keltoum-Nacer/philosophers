/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:48:24 by knacer            #+#    #+#             */
/*   Updated: 2024/05/15 14:07:00 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if(gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday()failed\n", 22);
	return(time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milli_sec)
{
	size_t	start_time;

	start_time = get_current_time();
	while(get_current_time() - start_time < milli_sec)
		usleep(500);
	return(0);
}