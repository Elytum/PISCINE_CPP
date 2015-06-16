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
CFLAGS = -Wall -Wextra -Werror=
#--------------Name-------------------------#
NAME = megaphone

#--------------Sources----------------------#
SRCS =	megaphone.cpp

INC = -I./

OBJS	=	$(SRCS:.cpp=.o)

#--------------Actions----------------------#

all: clean $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INC) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CCFLAGS) -c  $(INC) $< -o $@

test: $(NAME)
	./$(NAME) "shhhhh... I think the students are asleep..."
	./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	./$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, fclean, clean, re 
