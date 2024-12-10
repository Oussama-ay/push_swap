# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/07 09:51:27 by oayyoub           #+#    #+#              #
#    Updated: 2024/12/10 12:06:21 by oayyoub          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

FT_PRINTF =	ft_printf.c
SRCS =	list_tools.c utils.c the_core.c ft_split.c operations.c check_error.c $(FT_PRINTF)\
		instructions_push.c instructions_rotate.c instructions_swap.c instructions_reverse_rotate.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
