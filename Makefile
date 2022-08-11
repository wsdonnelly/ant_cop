# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 15:06:38 by wdonnell          #+#    #+#              #
#    Updated: 2022/08/11 15:16:02 by wdonnell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ant_cop
CC 		= clang
CFLAGS	= -Wall -Wextra -Werror -g -O3
SRCS	= ant_cop.c functions.c ft_strsplit.c
OBJS	= $(SRCS:.c=.o)
INCLD	= ant_cop.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS) $(INCLD)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all