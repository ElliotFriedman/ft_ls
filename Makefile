# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efriedma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/24 23:09:33 by efriedma          #+#    #+#              #
#    Updated: 2018/07/26 22:01:47 by efriedma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -g -Werror -Wall -Wextra -I ft_printf/libft -I ft_printf/includes

NAME = ft_ls

SRCS = main.c \
	   get_opt.c \

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ft_printf
	gcc $(OBJ) ft_printf/libftprintf.a -o $(NAME)

clean:
	rm $(OBJ)
	rm $(NAME)
	@$(MAKE) -C ft_printf clean

fclean: clean
	@$(MAKE) -C $(LIBFT) fclean
	rm $(NAME)

re: fclean $(NAME)
