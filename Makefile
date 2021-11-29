# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qkherzi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 16:48:35 by qkherzi           #+#    #+#              #
#    Updated: 2021/10/29 17:05:30 by qkherzi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minitalk

CLIENT			= client

SERVEUR			= server
CC				= gcc
RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror #-fsanitize=address

FOLDER_HEADER	= header/
FOLDER_SRC		= src/

HEADER_SRC		= Minitalk.h
SRC_CLIENT		= client.c utils.c utils2.c
SRC_SERVEUR		= server.c utils.c utils2.c

HDR				= $(addprefix ${FOLDER_HEADER}, ${HEADER_SRC})
SRC_C			= $(addprefix ${FOLDER_SRC}, ${SRC_CLIENT})
SRC_S			= $(addprefix ${FOLDER_SRC}, ${SRC_SERVEUR})

OBJ_C			= ${SRC_C:.c=.o}
OBJ_S			= ${SRC_S:.c=.o}
OBJ				= ${SRC_C:.c=.o} ${SRC_S:.c=.o}


%.o: %.c
			${CC} ${CFLAGS} -c -o $@ $<

${NAME}:	${CLIENT} ${SERVEUR}

${CLIENT}:	${OBJ_C} ${HDR}
				${CC} ${CFLAGS} ${OBJ_C} -o ${CLIENT}

${SERVEUR}:	${OBJ_S} ${HDR}
				${CC} ${CFLAGS} ${OBJ_S} -o ${SERVEUR}


all:			${NAME}

clean:
			${RM} ${OBJ}

fclean:			clean
			${RM} ${CLIENT} ${SERVEUR}

re:			fclean all

norm:
			norminette header/ src/

.PHONY:			all clean fclean re bonus norm
