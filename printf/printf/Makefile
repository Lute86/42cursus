LIB = ar rcs
RM = rm -f
CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC = ft_printf.c
UTILS = utils/ft_print_char.c utils/ft_print_hex_cap.c utils/ft_print_hex_low.c \
	utils/ft_print_int.c utils/ft_print_pointer.c utils/ft_print_str.c utils/ft_print_uint.c \
	utils/ft_putnbr_base.c utils/ft_putchar.c utils/ft_putstr.c utils/ft_putnbr.c \
	utils/ft_putnbr_pointer.c
B_SRC = 
OBJ = $(SRC:.c=.o) $(UTILS:.c=.o)
BONUSOBJ = $(B_SRC:.c=.o)
INCLUDE = libftprintf.h

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ)

bonus: $(OBJ) $(BONUSOBJ) $(INCLUDE)
	$(LIB) $(NAME) $(BONUSOBJ) $(OBJ)
	
%.o: %.c Makefile $(INCLUDE)
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ) $(BONUSOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all bonus clean fclean re
