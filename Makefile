# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/30 16:58:46 by rreedy            #+#    #+#              #
#    Updated: 2018/08/30 17:43:54 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pushswap
CHECKER := checker
LIB := libftprintf

POBJS := $(patsubst %.c,%.o,$(wildcard ./$(NAME)/*.c))
COBJS := $(patsubst %.c,%.o,$(wildcard ./$(CHECKER)/*.c))
LOBJS := $(patsubst %.c,%.o,$(wildcard ./$(LIB)/*.c))

CFLAGS += -Wall -Wextra -Werror -I./includes -I./$(LIB)/includes
LFLAGS += -L./ -lftprintf

.PHONY := all clean fclean

all: $(NAME)

$(NAME): $(POBJS) $(LIB) $(CHECKER)
	$(CC) $(CFLAGS) $(LFLAGS) -o $(NAME)

$(CHECKER): $(COBJS)
	$(CC) $(CFLAGS) $(LFLAGS) -o $(CHECKER)

$(LIB): $(LOBJS)
	ar rc $(LIB).a $(LOBJS)
	ranlib $(LIB).a

clean:
	@- $(RM) $(POBJS) $(COBJS) $(LOBJS)

fclean: fclean
	@- $(RM) $(NAME) $(CHECKER) $(LIB)/$(LIB).a

re: fclean all
