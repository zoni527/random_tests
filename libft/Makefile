# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 11:09:00 by jvarila           #+#    #+#              #
#    Updated: 2025/03/12 15:05:46 by jvarila          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libft.a

CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror
DEBUGFLAGS	:= -g
AR		:= ar -crs
# ---------------------------------------------------------------------------- #
SRC_DIR		:= ./
INC_DIR		:= ./
OBJ_DIR		:= ./obj
# ---------------------------------------------------------------------------- #
HF		:= libft.h
# ---------------------------------------------------------------------------- #
SRC :=	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isascii.c \
	ft_isprint.c	ft_isspace.c \
	\
	ft_strlen.c \
	ft_memset.c	ft_bzero.c	ft_memcpy.c	ft_memmove.c \
	\
	ft_strlcpy.c	ft_strlcat.c \
	\
	ft_toupper.c	ft_tolower.c \
	\
	ft_strchr.c	ft_strrchr.c \
	\
	ft_strncmp.c \
	\
	ft_memchr.c	ft_memcmp.c \
	\
	ft_strnstr.c \
	\
	ft_atoi.c \
	\
	ft_calloc.c \
	\
	ft_strdup.c \
	\
	ft_substr.c	ft_strjoin.c	ft_strtrim.c	ft_split.c \
	ft_itoa.c \
	\
	ft_strmapi.c	ft_striteri.c \
	\
	ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c \
	\
	ft_lstnew.c	ft_lstadd_front.c	ft_lstsize.c	\
	ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c	\
	ft_lstiter.c	ft_lstmap.c		ft_lstclear.c	\
	\
	get_next_line.c	get_next_line_utils.c \
	\
	ft_printf.c					\
	handle_c.c	handle_s.c	handle_p.c	\
	handle_d.c	handle_i.c	handle_u.c	\
	handle_hex_lowercase.c	handle_hex_uppercase.c	\
	\
	ft_putstr.c	ft_putchar.c	ft_putendl.c \
	\
	ft_isnumstr.c			ft_contains_duplicate_char.c	\
	ft_valid_multinumberstring.c	ft_valid_hex_string.c		\
	\
	ft_word_count.c	ft_char_index.c	ft_count_char.c \
	\
	ft_replace_char.c \
	\
	ft_skip_whitespace.c	ft_skip_char.c \
	\
	ft_atol.c	ft_atou_base.c	ft_atohex.c \
	\
	ft_putnbr.c	ft_putnbr_base.c \
	\
	ft_int_digits.c		ft_ulong_digits.c				\
	ft_uint_digits.c	ft_ulong_digits.c	ft_ulong_hex_digits.c	\
	\
	ft_free_ptr_return_int.c	ft_write_error_return_int.c	\
	ft_write_error_return_null.c \
	\
	ft_larger_int.c	ft_smaller_int.c \
	\
	ft_first_int_larger.c	ft_first_int_smaller.c \
	\
	ft_longtoa.c	ft_hextoa.c	ft_utoa.c	ft_ulongtoa.c \
	\
	ft_free_split.c \
	\
	ft_iabs.c \
	\
	ft_islower.c	ft_isupper.c \
	\
	ft_toggle_bool.c \
	\
	ft_realloc.c \
	\
	ft_new_memarena.c	ft_ma_malloc.c		ft_ma_calloc.c		\
	ft_free_memarena_exit.c	ft_free_memarena.c	ft_reset_memarena.c	\
	\
	ft_ma_strjoin.c	ft_ma_strdup.c	ft_ma_substr.c	ft_ma_split.c	\
	\
	ft_is_empty_string.c \
	ft_is_whitespace_string.c \
	\
	ft_strcmp.c

OBJ	:= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
# ---------------------------------------------------------------------------- #
all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(HF)
	$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HF)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
#------------------------------------------------------------------------------#
clean:
	rm -rf $(OBJ_DIR)

fclean:
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)

re: fclean all
# ---------------------------------------------------------------------------- #
debug: CFLAGS += $(DEBUGFLAGS)
debug: re
# ---------------------------------------------------------------------------- #
.PHONY: clean fclean re debug
# ---------------------------------------------------------------------------- #
