# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/05 12:58:43 by agrossma          #+#    #+#              #
#    Updated: 2019/03/10 18:47:03 by agrossma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		:= /bin/bash

################################################################################
# Start of system configuration section                                        #
################################################################################

NAME		:= lem-in
CC			:= gcc
CFLAGS		+= -Wall -Wextra -Werror -Ofast -flto -march=native
MKDIR		:= mkdir -p
RM			:= rm -f
RMDIR		:= rmdir
ECHO		:= echo
QUIET		:= @
MAKE		:= make

################################################################################
# End of system configuration section                                          #
################################################################################

################################################################################
# Start of files definition section                                            #
################################################################################

_INCLUDE	:= include/
INCLUDE		:= \
	lem_in.h
CFLAGS		+= -I$(_INCLUDE)
_SRC		:= src/
SRC			:= \
	main.c \
	parsing.c \
	parsing_nant.c \
	resolve.c \
	queue.c \
	edmonds_karp.c \
	augmenting_path.c \
	turns.c \
	path_size.c \
	realloc_path.c
_OBJ		:= obj/
OBJ			+= $(addprefix $(_OBJ), $(SRC:.c=.o))

################################################################################
# End of files definition section                                              #
################################################################################

################################################################################
# Start of libraries definition section                                        #
################################################################################

_LIBFT		:= libft/
CFLAGS		+= -I$(_LIBFT)$(_INCLUDE)
LIBFT_A		:= libft.a
LIBFT		:= ft

################################################################################
# End of libraries definition section                                          #
################################################################################

################################################################################
# Start of linking configuration section                                       #
################################################################################

LD			:= gcc
LDFLAGS		:= -L$(_LIBFT) -Wall -Wextra -Werror -Ofast -flto -march=native
LDLIBS		:= -l$(LIBFT)

################################################################################
# End of linking configuration section                                         #
################################################################################

################################################################################
# Start of rules definition section                                            #
################################################################################

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(_LIBFT)$(LIBFT_A) $(_OBJ) $(OBJ)
	$(QUIET)$(ECHO) "[$(NAME)]	LD	$@"
	$(QUIET)$(LD) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $@

$(_LIBFT)$(LIBFT_A):
	$(QUIET)$(MAKE) -C $(_LIBFT)

$(_OBJ):
	$(QUIET)$(MKDIR) $(_OBJ)

$(_OBJ)%.o: $(_SRC)%.c $(_INCLUDE)$(INCLUDE)
	$(QUIET)$(ECHO) "[$(NAME)]	CC	$(notdir $@)"
	$(QUIET)$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(QUIET)$(ECHO) "[$(NAME)]	RM	$(_OBJ)"
	$(QUIET)$(RM) $(OBJ)
	$(QUIET)if [ -d "$(_OBJ)" ]; then \
		$(RMDIR) $(_OBJ); \
	fi
	$(QUIET)$(MAKE) -C $(_LIBFT) $@

fclean: clean
	$(QUIET)$(ECHO) "[$(NAME)]	RM	$(NAME)"
	$(QUIET)$(RM) $(NAME)
	$(QUIET)$(MAKE) -C $(_LIBFT) $@

re: fclean all

################################################################################
# End of rules definition section                                              #
################################################################################
