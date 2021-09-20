# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 13:28:02 by wvaara            #+#    #+#              #
#    Updated: 2021/09/17 17:40:00 by wvaara           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftdprintf.a

SRC_DIR = srcs/

OBJ_DIR = obj/

LIBFT_DIR = ../

FLAGS = -c -Wall -Wextra -Werror

HEADER = includes/ft_dprintf.h

SRCS = $(addprefix $(SRC_DIR), ft_daddress.c ft_dadhoc_atoi.c \
	ft_dcap_l_round.c ft_dcharacter.c ft_dcheck_for_negative.c ft_dextras.c \
	ft_dflags.c ft_dfloat.c	ft_dformat_diu.c ft_dformat_float.c \
	ft_dformat_str.c ft_dhandle_flags.c ft_dhandle_float_flags.c \
	ft_dhandle_hash.c ft_dhexa_len.c ft_dhexa.c ft_dhexadecimal.c \
	ft_dint_format.c ft_dint.c ft_dnegative_hex.c ft_dpercentage.c \
	ft_dprint_additional.c ft_dprintf.c ft_dremove_neg.c ft_dreset_flags.c \
	ft_dreset_n.c ft_drounding.c ft_dsave_arg.c ft_dsave_hex_arg.c \
	ft_dspecifiers.c ft_dstring.c ft_dto_binary.c ft_dunsigned_int.c \
	ft_dvalidate_flags.c ft_dhandle_nan_inf.c)

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
