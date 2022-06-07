/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:49:25 by ahinani           #+#    #+#             */
/*   Updated: 2022/06/04 18:08:13 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_init_all(t_info *info, int ac, char **av)
{
	if (!info)
		return (FT_FAILURE);
	ft_get_args(info, ac, av);
	if (ft_check_args(*info, ac))
		return (FT_FAILURE);
	info->philo = malloc(sizeof(t_philo) * info->number_of_philosophers);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->number_of_philosophers);
	if (!info->philo || !info->forks)
		return (FT_FAILURE);
	info->finish = false;
	info->all_ate = 0;
	ft_init_mutex(info);
	ft_create_philos(info);
	return (FT_SUCCESS);
}