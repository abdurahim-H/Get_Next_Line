# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 17:08:51 by abhudulo          #+#    #+#              #
#    Updated: 2023/11/15 11:29:00 by abhudulo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = myfunction.a

SRC	=	get_next_line.c		\
		get_next_line_utils.c \

OBJS = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar crs

GREEN=\033[0;32m
RED=\033[0;31m
YELLOW=\033[0;33m
BLUE=\033[0;34m
PURPLE=\033[0;35m
CYAN=\033[0;36m
NC=\033[0m

$(NAME): $(OBJS)
	@echo "$(GREEN)Creating library...$(NC)"
	@$(AR) $@ $^

%.o: %.c
	@echo "$(CYAN)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)
	@echo "$(YELLOW)All targets have been built.$(NC)"

clean:
	@echo "$(RED)Cleaning up...$(NC)"
	@$(RM) $(OBJS)

fclean:	clean
	@echo "$(PURPLE)Full clean...$(NC)"
	@$(RM) $(NAME)		

re:	fclean all
	@echo "$(BLUE)All targets have been rebuilt.$(NC)"
