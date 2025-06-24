# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/05 13:40:35 by dwotsche          #+#    #+#              #
#    Updated: 2025/06/16 16:11:06 by dwotsche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
NAME = libft.a
all: $(NAME)
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all

MAIN = main
MAIN_SRC = main.c
$(MAIN): $(MAIN_SRC) $(NAME)
	@echo "Compiling main test program $@"
	$(CC) $(CFLAGS) $(MAIN_SRC) -L. -lft -o $(MAIN)
run: $(MAIN)
	./$(MAIN)
.PHONY: all clean fclean re
