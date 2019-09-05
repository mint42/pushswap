# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/30 16:58:46 by rreedy            #+#    #+#              #
#    Updated: 2019/09/04 17:23:45 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHEKR := checker
PSWAP := push_swap
LIB := libft/libft.a

CHECK_OBJS := $(patsubst %.c,%.o,$(wildcard ./srcs/checker/*.c))
PSWAP_OBJS := $(patsubst %.c,%.o,$(wildcard ./srcs/pushswap/*.c))
STACK_OBJS := $(patsubst %.c,%.o,$(wildcard ./srcs/stack/*.c))

CC := gcc
INCLUDES := -I./includes/pushswap -I./includes/checker -I./includes/stack -I./libft/includes -I./libft/includes/ft_printf
CFLAGS += -Wall -Wextra -Werror $(INCLUDES)
LFLAGS += -L./libft -lft

.PHONY: all clean fclean re name

all: name

name: $(CHEKR) $(PSWAP)

$(CHEKR): $(LIB) $(STACK_OBJS) $(CHECK_OBJS)
	$(CC) $(CFLAGS) $(STACK_OBJS) $(CHECK_OBJS) -o $(CHEKR) $(LFLAGS)

$(PSWAP): $(LIB) $(STACK_OBJS) $(PSWAP_OBJS)
	$(CC) $(CFLAGS) $(STACK_OBJS) $(PSWAP_OBJS) -o $(PSWAP) $(LFLAGS)

$(LIB):
	@- make -C libft/ all

clean:
	@- $(RM) $(CHECK_OBJS) $(PSWAP_OBJS) $(STACK_OBJS)
	@- make -C libft/ clean

fclean: clean
	@- $(RM) $(PSWAP) $(CHEKR)
	@- make -C libft/ fclean

re: fclean all
