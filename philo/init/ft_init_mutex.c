/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:46:02 by ahinani           #+#    #+#             */
/*   Updated: 2022/05/29 14:04:38 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_init_mutex(t_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_init(&info->finish_lock, NULL);
	while (i < info->number_of_philosophers)
		pthread_mutex_init(&info->forks[i++], NULL);
}