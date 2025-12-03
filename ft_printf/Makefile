# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zoeschne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/07 16:05:54 by zoeschne          #+#    #+#              #
#    Updated: 2025/05/14 10:39:46 by zoeschne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###	ARGUMENTS	###
NAME	= libftprintf.a
CFLAGS	= -Wall -Werror -Wextra
CC	= cc

###	SOURCES		###
SRCS	= ft_printf.c ft_strlen.c print_char.c print_ptr.c def_format.c printn_base.c print_str.c print_num.c

OBJS	= $(SRCS:.c=.o)

###	RULES		###
all	: ${NAME}

${NAME}	: ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean	:
	rm -f ${OBJS}

fclean	: clean
	rm -f ${NAME}

re	: fclean all

.PHONY	: all clean fclean re
