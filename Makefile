# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 13:58:33 by wvaara            #+#    #+#              #
#    Updated: 2021/07/14 17:30:25 by wvaara           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

FLAGS = -Wall -Wextra -Werror

SRCS = ft_file_stat.c main.c ft_no_flags.c ft_parse_args.c \
	ft_reserve_memory.c ft_save_all_args.c ft_organize_args.c ft_ls.c \
	ft_capital_r.c ft_print_entries.c ft_print_list.c ft_mod_time.c \
	ft_print_stats.c ft_order_by_time.c ft_ascii_order.c ft_dots.c \
	ft_save_entries.c ft_free.c ft_organize_dirs.c ft_organize_files.c \
	ft_organize_errors.c ft_handle_valid_files.c ft_handle_directories.c \
	ft_modify_name.c ft_check_rights.c ft_modify_file.c ft_set_rights.c \
	ft_check_path.c ft_check_dir_path.c ft_parse_output.c ft_check_link.c \
	ft_parse_rec_output.c

OBJECTS = $(SRCS:.c=.o)

INCLUDES = includes/

LIBRARIES = libft/libft.a libft/libftprintf.a

LIB_DIR = libft

all: $(NAME)

$(NAME): $(LIBRARIES)
	gcc -c $(FLAGS) $(SRCS)
	gcc $(FLAGS) -g $(LIBRARIES) $(OBJECTS) -I $(INCLUDES) -o $(NAME)

$(LIBRARIES):
	$(MAKE) -C $(LIB_DIR)

clean:
	$(MAKE) -C $(LIB_DIR) clean
	rm -rf $(OBJECTS)

fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: fclean all

.Phony: all clean fclean re
