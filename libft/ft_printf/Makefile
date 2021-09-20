# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 13:28:02 by wvaara            #+#    #+#              #
#    Updated: 2021/09/16 14:20:10 by wvaara           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_DIR = srcs/

OBJ_DIR = obj/

LIBFT_DIR = ../

FLAGS = -c -Wall -Wextra -Werror

HEADER = includes/ft_printf.h

SRCS = $(addprefix $(SRC_DIR), ft_address.c ft_adhoc_atoi.c ft_cap_l_round.c \
	ft_character.c ft_check_for_negative.c ft_extras.c ft_flags.c ft_float.c \
	ft_format_diu.c ft_format_float.c ft_format_str.c ft_handle_flags.c \
	ft_handle_float_flags.c ft_handle_hash.c ft_hexa_len.c ft_hexa.c \
	ft_hexadecimal.c ft_int_format.c ft_int.c ft_negative_hex.c \
	ft_percentage.c ft_print_additional.c ft_printf.c ft_remove_neg.c \
	ft_reset_flags.c ft_reset_n.c ft_rounding.c ft_save_arg.c \
	ft_save_hex_arg.c ft_specifiers.c ft_string.c ft_to_binary.c \
	ft_unsigned_int.c ft_validate_flags.c ft_handle_nan_inf.c)

OBJECTS = $(addprefix $(OBJ_DIR), $(SRCS:$(SRC_DIR)%.c=%.o))

LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
LIBFT_OBJECTS = $(wildcard libft/*.o)

INCLUDES = -I libft

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJECTS) $(LIBFT)
	@ar rcs $@ $(OBJECTS) $(LIBFT_OBJECTS)
	@mv $(NAME) ../

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@gcc $(FLAGS) -o $@ $< $(INCLUDES)

$(OBJ_DIR):
	@mkdir $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(addprefix $(LIBFT_DIR), $(NAME))

re: fclean all

.Phony: all clean fclean re
