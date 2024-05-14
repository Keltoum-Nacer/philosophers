/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:20:43 by knacer            #+#    #+#             */
/*   Updated: 2024/05/13 14:21:21 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int   is_alpha(char **av)
{
    int i;
    int j;

    i = 1;
    while(av[i])
    {
    	j = 0;
        while(av[i][j])
        {
            if (av[i][j] < '0' || av[i][j] > '9')
            {
                printf("error, you have to enter the right arguments\n");
                return(1);   
            }
            j++;
        }
        i++;
    } 
    return(0);   
}

int	ft_atoi(const char *str)
{
	long	x;
	int		i;
	int		s;

	x = 0;
	s = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-')
	{
		s = -s;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		x = x * 10 + (str[i] - '0');
		i++;
	}
	return (s * x);
}

