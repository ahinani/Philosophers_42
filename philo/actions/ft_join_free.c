/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:24:04 by ahinani           #+#    #+#             */
/*   Updated: 2022/06/04 14:05:26 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_join_free(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->number_of_philosophers)
		pthread_join(info->philo[i++].thread, NULL);
	free(info->philo);
	i = 0;
	while (i < info->number_of_philosophers)
		pthread_mutex_destroy(&info->forks[i++]);
	pthread_mutex_destroy(&info->finish_lock);
	free(info->forks);
	free(info);
}