/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:28:55 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:33:26 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../../includes/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_printf
{
	int						i;
	int						ii;
	int						check;
	int						prec;
	int						c_count;
	int						count;
	int						ret;
	int						minus;
	int						save_neg;
	int						plus;
	int						neg;
	int						dot;
	int						hash;
	int						num;
	int						save;
	int						save_dot;
	int						xtra;
	int						str_len;
	int						str_len_xtra;
	int						len;
	int						waste;
	int						precision;
	int						negative;
	int						base;
	int						o;
	int						h;
	int						hh;
	int						l;
	int						f;
	int						ll;
	int						inf;
	int						nan;
	int						cap_l;
	long long				n;
	int						u;
	long long				int_part;
	int						id;
	int						just_dot;
	int						d_zero;
	int						x;
	int						d_or_i;
	int						cap_x;
	long double				f_n;
	int						flag[55000];
	unsigned int			un;
	long int				ln;
	unsigned long			uln;
	long long				lln;
	signed char				hhn;
	long long				hn;
	unsigned short			uhn;
	unsigned long long		ulln;
	int						uhhn;
	unsigned char			ohhn;
	char					next;
	char					zero;
	char					space;
	char					roundup;
	char					star;
	char					*deci;
	va_list					copy;
	va_list					orig;
}							t_printf;

int						ft_printf(const char *str, ...);
int						ft_string_flag(const char *format, t_printf *data);
int						ft_specifiers(const char *format, t_printf *data);
int						ft_format_str(const char *format, t_printf *data);
int						ft_adhoc_atoi(const char *str, t_printf *data);
int						ft_hexa_len(t_printf *data, unsigned long long n);
int						ft_flags(const char *format, t_printf *data);
void					ft_string(t_printf *data);
void					ft_validate_flags(const char *format, t_printf *data);
void					ft_character(t_printf *data);
void					ft_address(t_printf *data);
void					ft_int(t_printf *data);
void					ft_int_format(t_printf *data);
void					ft_unsigned_int(t_printf *data);
void					ft_percentage(t_printf *data);
void					ft_reset_flags(t_printf *data);
void					ft_remove_neg(t_printf *data);
void					ft_hexadecimal(t_printf *data, unsigned long long n);
void					ft_save_arg(t_printf *data);
void					ft_hexa(t_printf *data);
void					ft_negative_hex(t_printf *data);
void					ft_reset_n(t_printf *data);
void					ft_save_hex_arg(t_printf *data);
void					ft_handle_hash(t_printf *data);
void					ft_check_for_negative(t_printf *data);
void					ft_float(t_printf *data);
void					ft_handle_flags(t_printf *data);
void					ft_cap_l_round(t_printf *data);
void					ft_handle_float_flags(t_printf *data);
void					ft_format_float(t_printf *data);
void					ft_format_diu(t_printf *data);
void					ft_rounding(t_printf *data);
void					ft_handle_nan_inf(t_printf *data);
int						ft_extras(t_printf *data);
int						ft_print_additional(t_printf *data);
char					*ft_to_binary(t_printf *data);

#endif
