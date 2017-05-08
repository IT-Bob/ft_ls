# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/06 17:18:16 by aguerin           #+#    #+#              #
#    Updated: 2017/05/05 17:19:56 by aguerin          ###   ########.fr        #
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
DRT = $(SRC)directory/

PTC =\
$(SRC)ft_ls.c\
$(FLG)find.c $(FLG)error.c\
$(LST)ls_lstnew.c
#$(NOE)
#$(STR)
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
