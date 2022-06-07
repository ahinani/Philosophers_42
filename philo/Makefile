# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 13:30:26 by ahinani           #+#    #+#              #
#    Updated: 2022/06/01 13:38:22 by ahinani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PHILO		=		actions/ft_down_fork.c			\
					actions/ft_grab_fork.c			\
					actions/ft_eating.c				\
					actions/ft_philo_actions.c		\
					actions/ft_print_msg.c			\
					actions/ft_sleep_then_tink.c	\
					actions/ft_join_free.c			\
					init/ft_check_args.c			\
					init/ft_get_args.c				\
					init/ft_init_mutex.c			\
					init/ft_init_philos.c			\
					init/ft_init_all.c				\
					utils/ft_atoi.c					\
					utils/ft_get_time.c				\
					utils/ft_strlen.c				\
					utils/ft_put_error.c			\
					philo.c


OBJ		=	$(PHILO:.c=.o)

CC			=	gcc
RM			=	rm -rf
CFLAGS		=	-Wall -Werror -Wextra
NAME		=	philo
HEADER		=	include/philo.h

all			:	$(NAME)

$(NAME)		:	$(OBJ) $(HEADER)
	@$(CC) $(CFLAGS) -I include $(OBJ) -o $@
	@echo "\n\033[3m\033[2;32m[*]\033[2;37m philo file was created succesfully ✅\033[0m\n"
	
%.o			:	%.c
	@$(CC) $(CFLAGS) -I include -c $< -o $(<:.c=.o)

clean		:
	@$(RM) $(OBJ)
	@echo "\n\033[3m\033[2;32m[*]\033[2;37m .o has been removed succesfully ✅\033[0m\n"
	
	
fclean		: clean
	@$(RM) $(OBJ)
	@$(RM) $(NAME)
	@echo "\n\033[3m\033[2;32m[*]\033[2;37m .o and philo has been removed succesfully ✅\033[0m\n"
	

re			:	fclean all

.PHONY		:	all bonus re clean fclean