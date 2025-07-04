# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmarrued <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 15:31:19 by cmarrued          #+#    #+#              #
#    Updated: 2024/12/19 15:31:21 by cmarrued         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap


SRCS = $(addsuffix .c, $(FILES))

OBJS = $(addsuffix .o, $(FILES))

FILES = push_swap push_swap_utils radix smallsort smallsort_utils reverse_rotate rotate swap push ft_strlen ft_atol ft_split index

CC	= cc

CFLAGS	= -Wall -Wextra -Werror

RM	= rm -rf


all:			${NAME}

${NAME}:		${OBJS} Makefile push_swap.h
			${CC} ${CFLAGS} ${SRCS} -o ${NAME}
								
clean:
			${RM} ${OBJS} 

fclean:			clean
				${RM} ${NAME}

re:			fclean all

.PHONY:			all clean fclean re
