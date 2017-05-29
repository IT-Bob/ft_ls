# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/06 17:18:16 by aguerin           #+#    #+#              #
#    Updated: 2017/05/29 13:58:48 by aguerin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = gcc
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I includes/ -I libft/includes/
CLIB = -L libft/ -lft
SRC = src/
FLG = $(SRC)flags/
STR = $(SRC)struct/
FLS = $(SRC)files/
LST = $(SRC)list/
NOE = $(SRC)nonex/
DRT = $(SRC)direc/
PRT = $(SRC)print/

PTC =\
$(SRC)error.c $(SRC)ft_ls.c\
$(DRT)add.c $(DRT)ls_direc.c\
$(FLG)find.c\
$(FLS)add.c $(FLS)long.c $(FLS)ls_files.c\
$(LST)ls_lstaddalpha.c $(LST)ls_lstaddtime.c $(LST)ls_lstdel.c $(LST)ls_lstiter.c $(LST)ls_lstiter_reverse.c $(LST)ls_lstnew.c $(LST)print.c\
$(NOE)add.c $(NOE)ls_nonex.c\
$(PRT)print_directory.c

PTO = $(PTC:.c=.o)

LIB = libft/libft.a

$(LIB):
	make -C libft all

all: $(NAME)

$(NAME): $(LIB) $(PTO)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(CLIB) $(PTO) -o $(NAME)

clean:
	make -C libft clean
	rm -f $(PTO)

fclean:
	make -C libft fclean
	rm -f $(PTO)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
