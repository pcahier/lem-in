# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 16:51:03 by agrossma          #+#    #+#              #
#    Updated: 2018/12/08 10:48:09 by agrossma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL			:= /bin/bash

#### Start of system configuration section ####

NAME			:= libft.a
CC				:= gcc
CFLAGS			+= -Wall -Wextra -Werror
AR				:= ar
ARFLAGS			:= -rc
RANLIB			:= ranlib
MKDIR			:= mkdir -p
RM				:= rm -f
RMDIR			:= rmdir
ECHO			:= echo
QUIET			:= @

#### End of system configuration section ####

#### Start of files definition section ####

_INCLUDE		:= include/
INCLUDE			:= \
	libft.h
CFLAGS			+= -I$(_INCLUDE)
_OBJ			:= obj/
_SRC			:= src/
_MEMORY_SRC		:= memory/
MEMORY_SRC		:= \
	ft_bzero.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \
	ft_memdel2d.c \
	ft_memrealloc.c \
	ft_memsize.c \
	ft_memmem.c \
	ft_memcalloc.c
OBJ				+= $(addprefix $(_OBJ), $(MEMORY_SRC:.c=.o))
_FT_PRINTF_SRC	:= ft_printf/
FT_PRINTF_SRC	:= \
	ft_printf.c \
	format.c \
	conv_string.c \
	print_padding.c \
	conv_tab.c \
	conv_wstring.c \
	conv_escape.c \
	conv_null.c \
	conv_pointer.c \
	conv_int.c \
	print_int_prefix.c \
	str_nbr_len.c \
	nbr_len.c \
	print_unsigned_int.c \
	ft_putwchar.c \
	conv_char.c \
	conv_wchar.c \
	conv_long.c \
	unsigned_length.c \
	conv_octal.c \
	conv_unsigned.c \
	conv_hex.c \
	ft_dprintf.c \
	ft_putwchar_fd.c
OBJ				+= $(addprefix $(_OBJ), $(FT_PRINTF_SRC:.c=.o))
_LIST_SRC		:= list/
LIST_SRC		:= \
	ft_lstadd.c \
	ft_lstdel.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstlen.c
OBJ				+= $(addprefix $(_OBJ), $(LIST_SRC:.c=.o))
_PRINT_SRC		:= print/
PRINT_SRC		:= \
	ft_putaddr.c \
	ft_putaddr_fd.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_iputchar.c
OBJ				+= $(addprefix $(_OBJ), $(PRINT_SRC:.c=.o))
_STRING_SRC		:= string/
STRING_SRC		:= \
	ft_atoi.c \
	ft_atoi_base.c \
	ft_extcmp.c \
	ft_getopt.c \
	ft_index.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_islower.c \
	ft_isprint.c \
	ft_isspace.c \
	ft_isupper.c \
	ft_itoa.c \
	get_next_line.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnlen.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_isnumber.c \
	ft_strsplitspace.c \
	ft_insert.c \
	ft_strmerge.c \
	ft_insert.c
OBJ				+= $(addprefix $(_OBJ), $(STRING_SRC:.c=.o))
_ARRAY_SRC		:= array/
ARRAY_SRC		:= \
	ft_2darraylen.c
OBJ				+= $(addprefix $(_OBJ), $(ARRAY_SRC:.c=.o))

#### End of files definition section ####

#### Start of linking configuration section ####

LDFLAGS			:=
LDLIBS			:=

#### End of linking configuration section ####

#### Start of rules section ####

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(_OBJ) $(OBJ)
	$(QUIET)$(ECHO) "[$(NAME)]	AR	$@"
	$(QUIET)$(AR) $(ARFLAGS) $@ $(OBJ)
	$(QUIET)$(RANLIB) $@

$(_OBJ):
	$(QUIET)$(MKDIR) $(_OBJ)

$(_OBJ)%.o: $(_SRC)$(_MEMORY_SRC)%.c $(_INCLUDE)$(INCLUDE)
	$(QUIET)$(ECHO) "[$(NAME)]	CC	$(_MEMORY_SRC)$(notdir $@)"
	$(QUIET)$(CC) $(CFLAGS) -c $< -o $@

$(_OBJ)%.o: $(_SRC)$(_FT_PRINTF_SRC)%.c $(_INCLUDE)$(INCLUDE)
	$(QUIET)$(ECHO) "[$(NAME)]	CC	$(_FT_PRINTF_SRC)$(notdir $@)"
	$(QUIET)$(CC) $(CFLAGS) -c $< -o $@

$(_OBJ)%.o: $(_SRC)$(_LIST_SRC)%.c $(_INCLUDE)$(INCLUDE)
	$(QUIET)$(ECHO) "[$(NAME)]	CC	$(_LIST_SRC)$(notdir $@)"
	$(QUIET)$(CC) $(CFLAGS) -c $< -o $@

$(_OBJ)%.o: $(_SRC)$(_PRINT_SRC)%.c $(_INCLUDE)$(INCLUDE)
	$(QUIET)$(ECHO) "[$(NAME)]	CC	$(_PRINT_SRC)$(notdir $@)"
	$(QUIET)$(CC) $(CFLAGS) -c $< -o $@

$(_OBJ)%.o: $(_SRC)$(_STRING_SRC)%.c $(_INCLUDE)$(INCLUDE)
	$(QUIET)$(ECHO) "[$(NAME)]	CC	$(_STRING_SRC)$(notdir $@)"
	$(QUIET)$(CC) $(CFLAGS) -c $< -o $@

$(_OBJ)%.o: $(_SRC)$(_ARRAY_SRC)%.c $(_INCLUDE)$(INCLUDE)
	$(QUIET)$(ECHO) "[$(NAME)]	CC	$(_ARRAY_SRC)$(notdir $@)"
	$(QUIET)$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(QUIET)$(ECHO) "[$(NAME)]	RM	$(_OBJ)"
	$(QUIET)$(RM) $(OBJ)
	$(QUIET)if [ -d "$(_OBJ)" ]; then \
		$(RMDIR) $(_OBJ); \
	fi

fclean: clean
	$(QUIET)$(ECHO) "[$(NAME)]	RM	$(NAME)"
	$(QUIET)$(RM) $(NAME)

re: fclean all

#### End of rules section ####
