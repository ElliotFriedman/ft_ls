# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efriedma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/24 23:09:33 by efriedma          #+#    #+#              #
#    Updated: 2018/11/15 22:32:16 by efriedma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -g -Werror -Wall -Wextra -I ft_printf/libft -I ft_printf/includes

NAME = ft_ls

FT_PRINTF = ft_printf

SRCS = main.c \
	   get_opt.c \

OBJ = $(SRCS:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(FT_PRINTF)
	gcc $(OBJ) ft_printf/libftprintf.a -o $(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(NAME)
	@$(MAKE) -C ft_printf clean

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)
