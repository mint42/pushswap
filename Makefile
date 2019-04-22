# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/30 16:58:46 by rreedy            #+#    #+#              #
#    Updated: 2019/04/22 03:34:54 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHEKR := checker
PSWAP := push_swap
LIB := lib/libft.a

CHECK_OBJS := $(patsubst %.c,%.o,$(wildcard ./srcs/checker/*.c))
PSWAP_OBJS := $(patsubst %.c,%.o,$(wildcard ./srcs/pushswap/*.c))
STACK_OBJS := $(patsubst %.c,%.o,$(wildcard ./srcs/stack/*.c))

CC := gcc
INCLUDES := -I./includes -I./lib/includes -I./lib/includes/ft_printf
CFLAGS += -g -Wall -Wextra -Werror $(INCLUDES)
LFLAGS += -L./lib -lft

.PHONY: all clean fclean re name

all: name

name: $(CHEKR) $(PSWAP)

$(CHEKR): $(LIB) $(STACK_OBJS) $(CHECK_OBJS)
	$(CC) $(CFLAGS) $(STACK_OBJS) $(CHECK_OBJS) -o $(CHEKR) $(LFLAGS)

$(PSWAP): $(LIB) $(STACK_OBJS) $(PSWAP_OBJS)
	$(CC) $(CFLAGS) $(STACK_OBJS) $(PSWAP_OBJS) -o $(PSWAP) $(LFLAGS)

$(LIB):
	@- make -C lib/ all

clean:
	@- $(RM) $(CHECK_OBJS) $(PSWAP_OBJS) $(STACK_OBJS)
	@- make -C lib/ clean

fclean: clean
	@- $(RM) $(PSWAP) $(CHEKR)
	@- make -C lib/ fclean

re: fclean all
