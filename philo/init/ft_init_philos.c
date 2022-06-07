/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 21:51:55 by ahinani           #+#    #+#             */
/*   Updated: 2022/06/05 22:28:55 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*ft_check_death(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (!philo->info->finish)
	{
		if ((philo->last_meal + philo->info->time_to_die) < ft_get_time())
		{
			ft_print_msg(philo, RED"died 💀"WHITE);
			philo->should_die = true;
			philo->info->finish = true;
		}
		usleep(100);
	}
	return (NULL);
}

void	*ft_check_hunger(void *arg)
{
	t_info	*info;

	info = arg;
	while (!info->finish)
	{
		if (info->all_ate == info->number_of_philosophers)
			info->finish = true;
	}
	return (NULL);
}

void	ft_create_philos(t_info *info)
{
	pthread_t	monitor;
	int			i;

	i = 0;
	info->creation_time = ft_get_time();
	while (i < info->number_of_philosophers)
	{
		info->philo[i].id = i;
		info->philo[i].info = info;
		info->philo[i].last_meal = info->creation_time;
		info->philo[i].should_die = false;
		info->philo[i].ate = 0;
		pthread_create(&info->philo[i].thread, NULL, philosophers,
			&info->philo[i]);
		pthread_create(&monitor, NULL, ft_check_death, &info->philo[i]);
		pthread_detach(monitor);
		i++;
		usleep(100);
	}
	if (info->number_of_times_each_philosopher_must_eat >= 0)
	{
		pthread_create(&monitor, NULL, ft_check_hunger, info);
		pthread_detach(monitor);
	}
}
