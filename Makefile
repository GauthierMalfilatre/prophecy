##
## FREE PROJECT, 2026
## PROPHECY
## File description:
## Makefile
##
SRC =   src/scheduler/scheduler_create.c \
		src/scheduler/scheduler_destroy.c \
		src/scheduler/scheduler_init.c \
		src/scheduler/scheduler_clear.c \
		src/scheduler/scheduler_addTask.c \
		src/scheduler/scheduler_update.c \
		\
		src/task/task_create.c \
		\
		src/minheap/minheap_add.c \
		src/minheap/minheap_remove.c \
		src/minheap/minheap_swap.c \

OBJ =   $(SRC:.c=.o)

NAME =  libprophecy.a

CC =    gcc
AR =    ar rc

CFLAGS += -Wall -Wextra -O3
CPPFLAGS += -Iinclude/

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
