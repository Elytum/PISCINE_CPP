# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achazal <achazal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:54:29 by achazal           #+#    #+#              #
#    Updated: 2014/12/13 12:55:35 by achazal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------Compilateur------------------#
CC = clang++
CFLAGS = -Wall -Wextra -Werror -I./
#--------------Name-------------------------#
NAME = phonebook

#--------------Sources----------------------#
FILES =	main.cpp		\
		PhoneBook.cpp	\
		contact.cpp


CURRENT_DIR = $(shell pwd)/$(NAME)
#--------------Actions----------------------#

all: clean $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(FILES) -o $(NAME)

clean:
	@rm -Rf $(NAME)

fclean:
	rm -Rf $(NAME)

re: fclean all

.PHONY: all, fclean, clean, re 
