/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:39:13 by ahinani           #+#    #+#             */
/*   Updated: 2022/06/04 18:03:59 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philosophers(void *arg)
{
	t_philo	*philo;
	int		right_fork;
	int		left_fork;

	philo = (t_philo *)arg;
	while (!philo->should_die && !philo->info->finish)
	{
		right_fork = philo->id;
		left_fork = (philo->id + 1) % philo->info->number_of_philosophers;
		ft_grab_fork(philo, right_fork);
		if (philo->info->number_of_philosophers == 1)
		{
			usleep(100000);
			break;
		}
		ft_grab_fork(philo, left_fork);
		ft_eating(philo);
		ft_down_fork(philo, right_fork, left_fork);
		ft_sleep_then_think(philo);
	}
	return (NULL);
}
