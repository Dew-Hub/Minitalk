# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 02:16:04 by buonturk          #+#    #+#              #
#    Updated: 2024/01/27 12:48:59 by buonturk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER			=	server
SERVER_SRC		=	server.c


CLIENT			=	client
CLIENT_SRC		=	client.c


UTILS_SRC		=	utils.c 

CC				=	gcc
RM 				=	rm -rf
FLAGS			= 	-Wall -Werror -Wextra


all : $(SERVER) $(CLIENT)

$(SERVER) :
	$(CC) $(FLAGS) $(SERVER_SRC) $(UTILS_SRC) -o $(SERVER)


$(CLIENT) :
	$(CC) $(FLAGS) $(CLIENT_SRC) $(UTILS_SRC) -o $(CLIENT)

clean :
	$(RM) $(SERVER) $(CLIENT)

fclean :
	$(RM) $(SERVER) $(CLIENT)

re : fclean all

.PHONY: all clean fclean re