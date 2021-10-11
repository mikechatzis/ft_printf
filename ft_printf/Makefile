# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/18 18:00:18 by mchatzip          #+#    #+#              #
#    Updated: 2021/06/19 14:35:53 by mchatzip         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME       = libftprintf.a

LIBFT_PATH = libft/

LIBFT_LIB  = libft.a

SRCS_FILES = alignment.c alignment2.c evalstring.c format.c ft_printf.c \
			 palignment.c printformat.c printformat2.c printformat3.c xtras.c xtras2.c
				
SRCS_OBJS  = ${SRCS_FILES:.c=.o}

CC         = gcc

CFLAGS     = -Wall -Wextra -Werror

RM         = rm -f

AR         = ar crs

LIBFT_OBJS    = ${LIBFT_PATH}*.o

LIBFTMAKE    = $(MAKE) -C ${LIBFT_PATH}

all:				${NAME}

${NAME}:    ${SRCS_OBJS} pmake
			${AR} ${NAME} ${SRCS_OBJS} ${LIBFT_OBJS}
			make clean ${LIBFT_PATH}

pmake:
			${LIBFTMAKE}

clean:
			make -C ${LIBFT_PATH} clean  
			${RM} ${SRCS_OBJS}

fclean: 	clean
			${RM} ${NAME}

re:         fclean all

.PHONY:     all clean fclean re