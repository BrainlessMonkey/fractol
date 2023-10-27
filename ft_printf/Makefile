# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adedieu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 02:39:38 by adedieu           #+#    #+#              #
#    Updated: 2022/12/01 03:32:44 by adedieu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c process_hexa.c process_number.c process_string.c ft_putchar_fd.c ft_putstr_fd.c

OBJS = $(addprefix ./srcs/, ${SRC:%.c=%.o})

AR = ar crs

NAME = ft_printf.a

RM = rm -f

all: $(NAME)

$(NAME):$(OBJS)
	$(AR) $(NAME) $^

%o: %.c
	$(CC) -o $@ -c $< $(FLAGS)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
