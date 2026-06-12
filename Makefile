##
## FREE PROJECT, 2026
## PROPHECY
## File description:
## Makefile
##
SRC =   src/

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
