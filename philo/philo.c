/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:26:22 by ahinani           #+#    #+#             */
/*   Updated: 2022/06/02 19:16:42 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int ac, char **av)
{
	t_info	*info;

	if (ac != 5 && ac != 6)
		return (ft_puterr(RED"Usage: ./philo <number_of_philos> <time_to_die>"
				"<time_to_eat> <time_to_sleep>\n"
				"<number_of_times_each_philosopher_must_eat>\n"WHITE));
	info = malloc(sizeof(*info));
	if (ft_init_all(info, ac, av) == FT_SUCCESS)
		ft_join_free(info);
	return (FT_SUCCESS);
}