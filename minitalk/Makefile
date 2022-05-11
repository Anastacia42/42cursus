# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 16:26:13 by ansilva-          #+#    #+#              #
#    Updated: 2022/05/11 16:54:08 by ansilva-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 
CLIENT = client
SERVER = server
LIBFT = ./libft/libft.a

SRC_C = client.c
SRC_S = server.c

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -I.
AR = ar rc

all: $(CLIENT) $(SERVER)

$(NAME): all

$(SERVER): $(SRC_S:=.o)
	$(AR) $(SERVER) $(SRC_S:=.o)

$(CLIENT): $(SRC_C:=.o)
	$(AR) $(CLIENT) $(SRC_C:=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SRC_C:=.o) $(SRC_S:=.o)

fclean: clean
	$(RM) $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re
