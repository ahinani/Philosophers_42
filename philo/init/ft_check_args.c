/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:51:47 by ahinani           #+#    #+#             */
/*   Updated: 2022/06/02 19:11:27 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_check_args(t_info info, int ac)
{
	if (ac == 6 && info.number_of_times_each_philosopher_must_eat <= 0)
		return (ft_puterr(RED"ERROR: wrong number of must eat\n"WHITE));
	if (info.number_of_philosophers < 0)
		return (ft_puterr(RED"ERROR: wrong number of philos\n"WHITE));
	if (info.time_to_die < 60)
		return (ft_puterr(RED"ERROR: wrong time to die\n"WHITE));
	if (info.time_to_eat < 60)
		return (ft_puterr(RED"ERROR: wrong time to eat\n"WHITE));
	if (info.time_to_sleep < 60)
		return (ft_puterr(RED"ERROR: wrong time to sleep\n"WHITE));
	return (FT_SUCCESS);
}