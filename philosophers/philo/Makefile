# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 12:20:10 by fahmadia          #+#    #+#              #
#    Updated: 2023/09/24 10:59:49 by fahmadia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH = src src/helper src/validation src/memory_management
SRCS = philo.c\
	ft_isdigit.c\
	ft_atoi.c\
	validation.c\
	ft_strlen.c\
	data.c\
	threads.c\
	routine.c\
	total_even_philos.c\
	total_odd_philos.c\
	actions.c\
	mutexes.c\
	time.c\
	free.c\
	monitor_num_eat.c\
	finish_simulation.c\
	monitor_philo_death.c\
	print.c
OBJS_PATH = objs
OBJS = $(patsubst %.c, $(OBJS_PATH)/%.o, $(SRCS))
CC = cc
CFLAGS = -c -MMD -Wall -Werror -Wextra -g -pthread
INCLUDE = -I./include
HEADERS = ./include/philo.h
NAME = philo
DEPENDENCIES = $(OBJS:.o=.d)

all: $(NAME) 

$(NAME): Makefile $(OBJS)
	$(CC) $(OBJS) -pthread -o $(NAME) 

$(OBJS_PATH)/%.o: %.c $(HEADERS)
	mkdir -p $(OBJS_PATH)
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@ 

clean:
	rm -f $(OBJS)
	rm -f $(DEPENDENCIES)
	rm -rf $(OBJS_PATH)
	rm -rf *.dSYM

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONEY: all clean fclean re

-include $(DEPENDENCIES)
