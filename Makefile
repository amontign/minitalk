# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amontign <amontign@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 09:20:11 by amontign          #+#    #+#              #
#    Updated: 2023/07/25 10:50:16 by amontign         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMESERVER = server
NAMECLIENT = client

CC = cc

SRCSERVER = utils.c \
	utils2.c \
	utils3.c \
	main_server.c \
	main_server2.c

SRCCLIENT = main_client.c \
	main_client2.c \
	utils.c \
	utils2.c \
	utils3.c

OBJSSERVER = ${SRCSERVER:.c=.o}
OBJSCLIENT = ${SRCCLIENT:.c=.o}

.c.o :
	${CC} -g -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

all: ${NAMESERVER} ${NAMECLIENT}

$(NAMESERVER): ${OBJSSERVER}
	${CC} -o ${NAMESERVER} ${OBJSSERVER}

$(NAMECLIENT): ${OBJSCLIENT}
	${CC} -o ${NAMECLIENT} ${OBJSCLIENT}

clean:
	rm -f ${OBJSSERVER} ${OBJSCLIENT}

fclean: clean
	rm -f ${NAMESERVER} ${NAMECLIENT}

re: fclean all

.PHONY: all clean fclean re
