# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 16:26:13 by ansilva-          #+#    #+#              #
#    Updated: 2022/06/20 11:19:28 by ansilva-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 
SERVER = server
CLIENT = client

PRINTF = printf/libftprintf.a
PRINTF_PATH = ./printf
LIBFT = Libft/libft.a
LIBFT_PATH = ./Libft

INC = minitalk.h

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -I.


all: $(LIBFT) $(PRINTF) $(SERVER) $(CLIENT) 

$(SERVER): $(SERVER:=.o) $(INC) 
	$(CC) $(CFLAGS) $(LIBFT) $(PRINTF) -o $(SERVER) $(SERVER:=.o)

$(CLIENT): $(CLIENT:=.o) $(INC)
	$(CC) $(CFLAGS) $(LIBFT) $(PRINTF) -o $(CLIENT) $(CLIENT:=.o)

$(PRINTF):
	make -C $(PRINTF_PATH)

$(LIBFT):
	make -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SERVER:=.o) $(CLIENT:=.o)
	make clean -C $(PRINTF_PATH)
	make clean -C $(LIBFT_PATH)

fclean: clean
	$(RM) $(SERVER) $(CLIENT)
	make fclean -C $(PRINTF_PATH)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re
