# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 11:14:30 by yshimoma          #+#    #+#              #
#    Updated: 2023/05/27 11:39:37 by yshimoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wordle
SRCS_DIR = ./src
SRCS = main.c
vpath %.c ${SRCS_DIR}
OBJ_DIR	= ./obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
DEP_DIR	= ./dep
DEPS = $(addprefix $(DEP_DIR)/, $(SRCS:.c=.d))
GNL_DIR = ./get_next_line
NAME_GNL = /get_next_line.a
INCLUDE = ./header
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS} ${DEPS}
	$(MAKE) -C ${GNL_DIR}
	${CC} -I${INCLUDE} ${GNL_DIR}${NAME_GNL} ${OBJS} -o $@

${OBJ_DIR}/%.o:%.c
	mkdir -p ${OBJ_DIR}
	${CC} ${CFLAGS} -I${INCLUDE} -c $< -o $@

${DEP_DIR}/%.d:%.c
	mkdir -p ${DEP_DIR}
	${CC} ${CFLAGS} -I${INCLUDE} -M $< > $@

clean:
	$(MAKE) clean -C ${GNL_DIR}
	${RM} ${OBJS} ${OBJ_DIR}
	${RM} ${DEPS} ${DEP_DIR}

fclean: clean
	${RM} ${NAME} ${NAME_GNL}

re: fclean all

-include ${DEPS}

.PHONY: all clean fclean re
