###	ARGUMENTS	###
NAME		= minitalk
SERVER		= server
CLIENT		= client
CFLAGS		= -Wall -Werror -Wextra -g3
CC			= cc

# ft_printf
PRINTF_DIR	= ft_printf
PRINTF_LIB	= $(PRINTF_DIR)/libftprintf.a

###	SOURCES		###
SERVER_SRC	= server.c mini_libft.c
CLIENT_SRC  = client.c mini_libft.c

SERVER_OBJ		= $(SERVER_SRC:.c=.o)
CLIENT_OBJ		= $(CLIENT_SRC:.c=.o)

OBJS = $(SERVER_OBJ) $(CLIENT_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

###	RULES		###
all	: ${NAME}

$(NAME): $(PRINTF_LIB) $(SERVER) $(CLIENT)

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

$(SERVER): $(SERVER_OBJ) $(PRINTF_LIB)
	$(CC) $(SERVER_OBJ) $(PRINTF_LIB) -o $(SERVER)

$(CLIENT): $(CLIENT_OBJ) $(PRINTF_LIB)
	$(CC) $(CLIENT_OBJ) $(PRINTF_LIB) -o $(CLIENT)

clean	:
	rm -f ${OBJS}
	make -C $(PRINTF_DIR) clean

fclean	: clean
	rm -f ${NAME}
	rm -f ${SERVER} ${CLIENT}
	make -C $(PRINTF_DIR) fclean

re	: fclean all

.PHONY	: all clean fclean re