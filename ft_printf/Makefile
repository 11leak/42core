# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/30 13:50:13 by dwotsche          #+#    #+#              #
#    Updated: 2025/07/03 11:13:08 by dwotsche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
all: $(NAME)
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o
clean:
	rm -f $(OBJS)
fclean:
	rm -f $(NAME)
re : fclean all

MAIN = main
MAIN_SRC = main.c
$(MAIN): $(MAIN_SRC) $(NAME)
	@echo "Compiling main test program... $@"
	$(CC) $(CFLAGS) $(MAIN_SRC) -L. -lft -o $(MAIN)
run: $(MAIN)
	./$(MAIN)
.PHONY: all clean fclean re
