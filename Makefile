# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/07 09:51:27 by oayyoub           #+#    #+#              #
#    Updated: 2025/01/05 16:33:43 by oayyoub          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -g
CFLAGS = -Wall -Wextra -Werror

SRCS =	push_swap.c sorting.c sorting_utils_b.c

SRCS_BONUS = checker_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c

UTILS = operations.c list_tools.c ft_printf.c instructions_reverse_rotate.c\
		instructions_rotate.c instructions_swap.c instructions_push.c\
		ft_split.c check_error.c  utils.c	

# Colors
RESET = \033[0m
BLACK = \033[1;30m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PURPLE = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m
RESET = \033[0m

# Special characters
ROCKET = 🚀
SPARK = ✨
GEAR = ⚙️
CHECK = ✓

OBJS = $(SRCS:.c=.o) $(UTILS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o) $(UTILS:.c=.o)
NAME = push_swap
NAME_BONUS = checker

all: logo $(NAME) success

logo:
	@clear
	@echo "\n\n"
	@echo "$(CYAN)Loading Turbo Sort Engine...$(RESET)"
	@sleep 0.5
	@echo "$(CYAN)"
	@echo "████████╗██╗   ██╗██████╗ ██████╗  ██████╗"
	@sleep 0.1
	@echo "╚══██╔══╝██║   ██║██╔══██╗██╔══██╗██╔═══██╗"
	@sleep 0.1
	@echo "   ██║   ██║   ██║██████╔╝██████╔╝██║   ██║"
	@sleep 0.1
	@echo "   ██║   ██║   ██║██╔══██╗██╔══██╗██║   ██║"
	@sleep 0.1
	@echo "   ██║   ╚██████╔╝██║  ██║██████╔╝╚██████╔╝"
	@sleep 0.1
	@echo "   ╚═╝    ╚═════╝ ╚═╝  ╚═╝╚═════╝  ╚═════╝"
	@echo ""
	@sleep 0.2
	@echo "	  ███████╗ ██████╗ ██████╗ ████████╗"
	@sleep 0.1
	@echo "	  ██╔════╝██╔═══██╗██╔══██╗╚══██╔══╝"
	@sleep 0.1
	@echo "	  ███████╗██║   ██║██████╔╝   ██║"
	@sleep 0.1
	@echo "	  ╚════██║██║   ██║██╔══██╗   ██║"
	@sleep 0.1
	@echo "	  ███████║╚██████╔╝██║  ██║   ██║"
	@sleep 0.1
	@echo "	  ╚══════╝ ╚═════╝ ╚═╝  ╚═╝   ╚═╝"
	@echo "$(GREEN)By: oayyoub$(RESET)"
	@echo "\n$(PURPLE)$(SPARK) Initializing Turbo Sort Components $(SPARK)$(RESET)"
	@sleep 0.5

$(NAME): $(OBJS)
	@echo "$(YELLOW)$(GEAR) Assembling components...$(RESET)"
	@$(CC) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(CHECK) Binary compilation complete$(RESET)"

bonus: $(OBJS_BONUS)
	@echo "$(YELLOW)$(GEAR) Assembling bonus components...$(RESET)"
	@$(CC) $(OBJS_BONUS) -o $(NAME_BONUS)
	@echo "$(GREEN)$(CHECK) Bonus compilation complete$(RESET)"

%.o: %.c
	@echo "$(CYAN)$(GEAR) Compiling $<...$(RESET)"
	@$(CC) -c $< -o $@
	@echo "$(GREEN)$(CHECK) Compiled $< successfully$(RESET)"

clean:
	@echo "$(YELLOW)$(GEAR) Cleaning object files...$(RESET)"
	@rm -rf $(OBJS) $(OBJS_BONUS)
	@echo "$(GREEN)$(CHECK) Cleanup complete$(RESET)"

fclean: clean
	@echo "$(YELLOW)$(GEAR) Deep cleaning binaries...$(RESET)"
	@rm -rf $(NAME) $(NAME_BONUS)
	@echo "$(GREEN)$(CHECK) Deep cleanup complete$(RESET)"

success:
	@echo "\n$(GREEN)$(ROCKET) Turbo Sort is ready for launch! $(ROCKET)$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re bonus logo success
