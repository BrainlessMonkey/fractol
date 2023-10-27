NAME  = fractol

SRC   = main.c init.c utils.c render.c events.c

OBJ   = $(SRC:.c=.o)

CC    = gcc

FLAGS = -Wall -Wextra -Werror -g

PRINTF = ft_printf/ft_printf.a

LIB = libft/libft.a

$(NAME): $(LIB) $(PRINTF) $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(LIB) $(PRINTF) -Lmlx -lmlx -L/usr/local/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	@${CC} ${FLAGS} -c $^ -o $@ 

RM = rm -f

all : $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
