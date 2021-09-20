# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/08 18:25:08 by wvaara            #+#    #+#              #
#    Updated: 2021/09/17 17:40:29 by wvaara           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FT_PRINTF = libftprintf.a

FT_DPRINTF = libftdprintf.a

FLAGS = -Wall -Wextra -Werror

INCLUDES = includes/

SRCS = ft_putnbr.c ft_putchar.c ft_strlen.c ft_putnbr.c ft_putstr.c \
	ft_strcpy.c ft_memset.c ft_strdup.c ft_strncpy.c ft_memcpy.c \
	ft_strncat.c ft_memccpy.c ft_memmove.c ft_strcmp.c ft_memchr.c \
	ft_strstr.c ft_strlcpy.c ft_strlcat.c ft_strncmp.c ft_memcmp.c \
	ft_strchr.c ft_putendl.c ft_strrchr.c ft_strnstr.c ft_isalpha.c \
	ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
	ft_tolower.c ft_atoi.c ft_bzero.c ft_memalloc.c ft_memdel.c ft_strsplit.c \
	ft_strnew.c ft_strcat.c ft_strdel.c ft_strclr.c ft_striter.c \
	ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
	ft_strsub.c ft_strjoin.c ft_strtrim.c ft_wordcount.c ft_strrev.c \
	ft_wordlength.c ft_itoa.c ft_intlen.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_lstdelone.c ft_lstdel.c \
	ft_lstadd.c ft_lstiter.c ft_lstnew.c ft_lstmap.c ft_linecount.c ft_gnl.c \
	ft_putaddr.c ft_addr_len.c ft_putlonglong.c ft_uns_longlong_len.c \
	ft_put_uns_longlong.c ft_uns_itoa.c ft_uns_longlong_len.c ft_isnan.c \
	ft_isinf.c ft_long_long_len.c ft_isupper.c ft_strcjoin.c ft_strndup.c \
	ft_find_char.c ft_strcdup.c ft_check_needle.c ft_get_next_word.c \
	ft_print_array.c ft_realloc_array.c ft_arrdup.c ft_free_array.c \
	ft_arrlen.c ft_remove_last_word.c ft_arr_trim.c ft_extract_word.c \
	ft_skip_white_space.c ft_isspace.c ft_str_char_trim.c ft_put_uns_ll_fd.c \
	ft_putaddr_fd.c ft_putlonglong_fd.c ft_extract_word_with_char.c

LIBRARY = $(SRCS:.c=.o)

all: $(NAME) $(FT_PRINTF) $(FT_DPRINTF)

$(NAME): $(SRCS)
	gcc -c $(FLAGS) $(SRCS) -I $(INCLUDES)
	ar rc $(NAME) $(LIBRARY)
	ranlib $(NAME)

$(SRCS): $(INCLUDES)libft.h

$(FT_PRINTF):
	$(MAKE) -C ft_printf

$(FT_DPRINTF):
	$(MAKE) -C ft_dprintf

clean:
	rm -f $(LIBRARY)
	$(MAKE) -C ft_printf clean
	$(MAKE) -C ft_dprintf clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ft_printf fclean
	$(MAKE) -C ft_dprintf fclean

re: fclean all

.Phony: all clean fclean re
