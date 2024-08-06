SRC = color.c events.c fractal.c  init.c parcing.c render.c sets.c utils.c
NAME = fractol

CC = cc
FLAGS = -Werror -Wextra -Wall
RM = rm -rf

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS)  -lmlx -framework OpenGL -framework AppKit $^ -o $@

%.o: %.c fractal.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all