CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB = -L./libft -lft
MAKE = make
NAME1 = checker
NAME2 = push_swap

SRCS1 += ./src/checker.c
SRCS1 += ./src/exec.c

SRCS2 += ./src/push_swap.c
SRCS2 += ./src/sort.c
SRCS2 += ./src/min.c

SRCS += ./src/check_range.c
SRCS += ./src/buff.c
SRCS += ./src/parsing.c
SRCS += ./src/push.c
SRCS += ./src/swap.c
SRCS += ./src/rotate.c
SRCS += ./src/reverse_rotate.c
SRCS += ./src/utils.c
SRCS += ./src/free_ressources.c

INC += ./inc/push_swap.h

OBJ = $(SRCS:.c=.o)
OBJ1 = $(SRCS1:.c=.o)
OBJ2 = $(SRCS2:.c=.o)

#compilation test
#ARG=`ruby -e "puts (0..10).to_a.shuffle.join(' ')"`; make && time ./push_swap $ARG | ./checker $ARG

all: $(NAME1) $(NAME2)

$(NAME1): libft $(OBJ1) $(OBJ) $(INC)
	$(CC) $(CFLAGS) $(LIB) -g $(SRCS1) $(SRCS) -o $@

$(NAME2): libft $(OBJ2) $(OBJ) $(INC)
	$(CC) $(CFLAGS) $(LIB) -g $(SRCS2) $(SRCS) -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ1) $(OBJ2) $(OBJ)
	cd ./libft && $(MAKE) clean

fclean: clean
	rm -rf $(NAME1) $(NAME2)
	cd ./libft && $(MAKE) fclean

re:	fclean all

.PHONY: libft
libft:
	cd ./libft && $(MAKE)
