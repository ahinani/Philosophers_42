/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:18:09 by ahinani           #+#    #+#             */
/*   Updated: 2022/06/04 18:55:59 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define WHITE "\033[0;37m"
# define YELLOW "\033[0;33m"
# define PURPLE "\033[0;35m"
# define FT_SUCCESS 0
# define FT_FAILURE 1

#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef	struct timeval t_time;

typedef struct s_philo
{
	int				id;
	int				ate;
	int				should_die;
	long long		last_meal;
	struct s_info	*info;
	pthread_t		thread;
} t_philo;

typedef	struct s_info
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				finish;
	int				all_ate;
	long long		creation_time;
	struct s_philo	*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t finish_lock;
} t_info;



int			ft_atoi(const char *str);
int			ft_strlen(char *str);
int			ft_puterr(char *err);
int			ft_check_args(t_info info, int ac);
int			ft_init_all(t_info *info, int ac, char **av);
void		ft_get_args(t_info *info, int ac, char **av);
void		ft_init_mutex(t_info *info);
void		ft_print_msg(t_philo *philo, char *msg);
long long	ft_current_time(t_philo *philo);
long long	ft_get_time(void);
void		ft_eating(t_philo *philo);
void		ft_sleep_then_think(t_philo *philo);
void		ft_grab_fork(t_philo *philo, int f);
void		ft_down_fork(t_philo *philo, int f1, int f2);
void		*philosophers(void *arg);
void		ft_create_philos(t_info *info);
void		ft_join_free(t_info *info);
#endif