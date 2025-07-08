# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/30 13:50:13 by dwotsche          #+#    #+#              #
#    Updated: 2025/07/08 16:30:30 by dwotsche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =	ft_printf.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
LIBFT = libft
LIBFT_A = $(LIBFT)/libft.a
LIBFT_MAKE = make -C $(LIBFT)
all: $(NAME)
$(NAME): $(OBJS) $(LIBFT)/libft.a
	cp $(LIBFT)/libft.a $(NAME)
	ar rc $(NAME) $(OBJS)
$(LIBFT)/libft.a:
	$(LIBFT_MAKE)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re : fclean all

MAIN = main
MAIN_SRC = main.c
$(MAIN): $(MAIN_SRC) $(NAME)
	@echo "Compiling main test program... $@"
	$(CC) $(CFLAGS) $(MAIN_SRC) -L. -lftprintf -o $(MAIN)
run: $(MAIN)
	./$(MAIN)
.PHONY: all clean fclean re
