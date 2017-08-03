NAME = ft_ls
SRC = sort.c dop.c perms.c serve_func.c \
item_creation.c item_print.c main.c 
FLAG = -Wall -Wextra -Werror
OBJ = $(subst .c, .o, $(SRC))

all: compile

compile:
	make -C ft_printf/
	gcc $(FLAG) -o $(NAME) $(SRC) ft_printf/libftprintf.a

clean:
	make clean -C ft_printf/
	rm -f $(OBJ)

fclean:clean
	make fclean -C ft_printf/
	rm -f $(NAME)

re:	fclean all
