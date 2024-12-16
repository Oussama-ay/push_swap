# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/07 09:51:27 by oayyoub           #+#    #+#              #
#    Updated: 2024/12/16 14:13:57 by oayyoub          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	push_swap.c sorting.c sorting_utils_a.c sorting_utils_b.c
		instructions_reverse_rotate.c instructions_rotate.c instructions_swap.c\
		instructions_push.c

SRCS_BONUS = checker_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c\

UTILS = operations.c list_tools.c ft_printf.c\
		ft_split.c check_error.c  utils.c\	

OBJS = $(SRCS:.c=.o) $(UTILS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o) $(UTILS:.c=.o)
NAME = push_swap
NAME_BONUS = checker

all: $(NAME) clean

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all
