# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 11:51:16 by ansilva-          #+#    #+#              #
#    Updated: 2022/06/15 11:52:16 by ansilva-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_isdigit ft_atoi\

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -I libft.h
AR = ar rc

all: $(NAME)

$(NAME): $(SRC:=.o)
	$(AR) $(NAME) $(SRC:=.o)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SRC:=.o)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re
