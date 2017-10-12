CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB = -L./libft -lft
MAKE = make
NAME = lem-in

SRCS += ./src/main.c
SRCS += ./src/parsing.c
SRCS += ./src/utils.c

INC += ./inc/lemin.h

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): libft $(OBJ) $(INC)
	$(CC) $(CFLAGS) $(LIB) -g $(SRCS) -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ)
	cd ./libft && $(MAKE) clean

fclean: clean
	rm -rf $(NAME)
	cd ./libft && $(MAKE) fclean

re:	fclean all

.PHONY: libft
libft:
	cd ./libft && $(MAKE)
