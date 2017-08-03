# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 09:49:16 by vrudakov          #+#    #+#              #
#    Updated: 2017/03/04 22:50:09 by vrudakov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCFLS = ft_atoi.c ft_memchr.c ft_strchr.c ft_strcpy.c ft_bzero.c ft_memcmp.c \
ft_putendl.c ft_tolower.c ft_isalnum.c ft_memcpy.c ft_strcmp.c ft_strlcat.c \
ft_toupper.c ft_isalpha.c ft_memcpy_rev.c ft_putnbr.c ft_strncpy.c ft_strlen.c \
ft_strnstr.c ft_isascii.c ft_strrchr.c ft_isdigit.c ft_memmove.c ft_striter.c \
ft_striteri.c ft_putstr.c ft_strdup.c ft_isprint.c ft_memset.c ft_strncat.c \
ft_strstr.c ft_memccpy.c ft_putchar.c ft_memalloc.c ft_strcat.c ft_strncmp.c \
ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_strmap.c ft_strmapi.c \
ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c 
PRINTF_SRC = iswhat.c ft_printf.c go_print_c_str.c go_print_str_s.c dop_f.c \
			 go_print_d.c go_print_x.c go_print_u.c go_print_o.c go_print_p_n.c\
			 nevlezlo.c go_print_c.c
PRINTF_OBJ = $(subst .c,.o,$(PRINTF_SRC))
OBJECTS = $(subst .c,.o,$(SRCFLS))

SRC_C = $(SRCFLS:%=libft/%) $(PRINTF_SRC)
SRC_O = $(SRC_C:.c=.o) $(PRINTF_OBJ)

all: $(NAME)

$(NAME): $(SRC_O)
	ar rc $(NAME) $(SRC_O) 
	ranlib $(NAME)

$(OBJECT): $(SRC_C)
	gcc -Wall -Wextra -Werror -c $(SRC_C)

clean:
	/bin/rm -f $(SRC_O)

fclean: clean
	/bin/rm -f $(NAME)

re:	fclean all
