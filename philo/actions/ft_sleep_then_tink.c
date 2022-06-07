/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep_then_tink.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:21:04 by ahinani           #+#    #+#             */
/*   Updated: 2022/06/04 19:19:39 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_sleep_then_think(t_philo *philo)
{
	ft_print_msg(philo, YELLOW"sleeping 💤\n"WHITE);
	usleep(philo->info->time_to_sleep * 1000);
	ft_print_msg(philo, PURPLE"thinking 💭\n"WHITE);
}