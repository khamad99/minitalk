# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 14:21:22 by kalshaer          #+#    #+#              #
#    Updated: 2023/01/23 20:29:06 by kalshaer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT	= libft/libft.a
NAME1	= client
NAME2	= server

SRCS1	= client.c
OBJS1	= $(SRCS1:%.c=%.o)
SRCS2	= server.c
OBJS2	= $(SRCS2:%.c=%.o)

SRCS_b1	= client_bonus.c
OBJS_b1	= $(SRCS_b1:%.c=%.o)
SRCS_b2	= server_bonus.c
OBJS_b2	= $(SRCS_b2:%.c=%.o)

FLAGS	= -Wall -Werror -Wextra
CC		= cc

$(NAME1): $(NAME2)
	$(MAKE) -C ./libft
	$(CC) $(FLAGS) -c $(SRCS1)
	$(CC) $(OBJS1) $(LIBFT) -o $(NAME1)

$(NAME2):
	$(MAKE) -C ./libft
	$(CC) $(FLAGS) -c $(SRCS2)
	$(CC) $(OBJS2) $(LIBFT) -o $(NAME2)

bonus: bonus2
	$(MAKE) -C ./libft
	$(CC) $(FLAGS) -c $(SRCS_b1)
	$(CC) $(OBJS_b1) $(LIBFT) -o $(NAME1)

bonus2:
	$(MAKE) -C ./libft
	$(CC) $(FLAGS) -c $(SRCS_b2)
	$(CC) $(OBJS_b2) $(LIBFT) -o $(NAME2)


all: $(NAME1) $(NAME2)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS1) $(OBJS2) $(OBJS_b1) $(OBJS_b2)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME1) $(NAME2)

re: fclean all