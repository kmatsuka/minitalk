NAME_S = server
SRCS_S = server.c
OBJS_S = $(SRCS_S:.c=.o)

NAME_C = client
SRCS_C = client.c
OBJS_C = $(SRCS_C:.c=.o)

NAME_SB = server_bonus
SRCS_SB = server_bonus.c
OBJS_SB = $(SRCS_SB:.c=.o)

NAME_CB = client_bonus
SRCS_CB = client_bonus.c
OBJS_CB = $(SRCS_CB:.c=.o)

LIBFT = ./libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME_S) $(NAME_C)

$(LIBFT):
	make -C ./libft

$(NAME_S): $(OBJS_S) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_S) $(LIBFT) -o server
	
$(NAME_C): $(OBJS_C) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_C) $(LIBFT) -o client

$(NAME_SB): $(OBJS_SB) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_SB) $(LIBFT) -o server_bonus
	
$(NAME_CB): $(OBJS_CB) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_CB) $(LIBFT) -o client_bonus

clean:
	make clean -C ./libft
	rm -f $(OBJS_S) $(OBJS_C)
	rm -f $(OBJS_SB) $(OBJS_CB)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME_S) $(NAME_C)
	rm -f $(NAME_SB) $(NAME_CB)

re: fclean all

bonus: $(NAME_SB) $(NAME_CB)

.PHONY: all clean fclean re bonus
