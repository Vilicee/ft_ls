/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:10:55 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/14 17:34:26 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/includes/libft.h"
# include "../libft/ft_printf/includes/ft_printf.h"
# include <sys/stat.h>
# include <dirent.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <dirent.h>
# include <sys/xattr.h>

typedef struct s_no_flags
{
	char			**entry;
	DIR				*dir;
	struct passwd	*pwd;
	struct group	*group;
	time_t			now;
	time_t			then;
	int				files;
	char			*rights;
	char			month[4];
	char			date[3];
	char			hour_min[6];
	char			year[5];
	char			old;
	char			l;
	char			extend;
	int				total;
	int				links;
	int				len;
	int				s_l;
	int				name;
	int				gr_int;
	long long		size;
	int				i;
	int				k;
	int				kk;
}					t_no_flags;

typedef struct s_args
{
	char			R;
	char			l;
	char			a;
	char			r;
	char			t;
	char			dir_input;
	char			valid_flag;
	char			options;
	char			*temp_ptr;
	char			*store;
	char			*temp;
	char			file;
	int				dash_input;
	int				index;
	int				i;
	int				argc;
	int				checker;
	int				errors;
	int				valid_files;
	int				valid_directories;
	struct stat		stats;
	DIR				*temp_dir;
}					t_args;

typedef struct s_input_data
{
	int				d;
	int				e;
	int				f;
	struct stat		stat_buf;
	char			**fil;
	char			**dirs;
	char			**err;
}					t_input_data;

int				ft_file_stat(char *file, t_no_flags *data);
int				ft_parse_rec_output(t_args *input, char *latter, char *former,
					char *temp);
int				ft_reserve_memory(t_args *input, t_input_data *data);
int				ft_ls(t_input_data *data, t_args *input);
int				ft_capital_r(t_args *input, char *path, char *name);
int				ft_dots(char *str);
char			*ft_check_dir_path(char *path, t_args *input);
int				ft_check_rights(t_input_data *data);
int				ft_check_path(char *ptr, char *argv);
void			ft_check_link(char *argv, struct stat *buf, t_args *input);
void			ft_parse_output(char *path, struct stat *buf, t_args *input);
void			ft_modify_file(char *path, t_input_data *data);
void			ft_modify_name(char *path, t_no_flags *data);
void			ft_organize_dirs(t_input_data *data, t_args *input);
void			ft_organize_files(t_input_data *data, t_args *input);
void			ft_organize_errors(t_input_data *data, t_args *input);
void			ft_handle_directories(t_input_data *data, t_args *input);
void			ft_handle_valid_files(t_input_data *data, t_args *input);
void			ft_open_dir(t_args *input, char *path);
void			ft_print_list(t_no_flags *data, t_args *input, char *path);
void			ft_print_stats(t_no_flags *data, struct stat *stats);
void			ft_ascii_order(t_no_flags *data);
int				ft_save_entries(t_no_flags *data, t_args *input, char *path);
void			ft_order_by_time(t_no_flags *data, t_args *input, char *path);
void			ft_list_files(char *argv);
void			ft_mod_time(t_no_flags *data, struct stat *stats);
void			ft_print_entries(t_args *input, t_no_flags *data);
void			ft_save_hidden_files(t_no_flags *data, t_args *input);
void			ft_no_flags(void);
int				ft_parse_args(t_args *input, char *argv);
void			ft_save_all_args(char *argv, t_input_data *data, t_args *input);
void			ft_free(t_no_flags *data);
void			ft_set_rights(t_no_flags *data, struct stat *stats);
void			ft_organize_args(t_input_data *data, t_args *input);

#endif