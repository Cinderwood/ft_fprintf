/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsunwoo <wsunwoo@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:48:23 by wsunwoo           #+#    #+#             */
/*   Updated: 2025/03/10 03:03:09 by wsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FPRINTF_H
# define FT_FPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <stdbool.h>
# include "libft.h"
# include "ansi_colors.h"
# define VAR_TYPE_LIST "cspdiuxX%"
# define LHEX "0123456789abcdef"
# define L_PREFIX "0x"
# define UHEX "0123456789ABCDEF"
# define U_PREFIX "0X"
# define DEC "0123456789"

typedef struct s_obj
{
	char	var_type;
	int		flag_minus;
	int		flag_plus;
	int		flag_space;
	int		flag_hash;
	int		flag_zero;
	int		width_true;
	int		width_num;
	int		precision_true;
	int		precision_num;
}	t_obj;

typedef struct s_colored_print
{
	const char	*prefix_str;
	const char	*prefix_color;
	const char	*text_color;
}	t_colored_print;

typedef t_colored_print	t_cp;

int			cp_perror(const char *format, ...);
t_cp		*cp_init(const char *prefix_str, const char *prefix_color, \
const char *text_color);
void		cp_destroy(t_cp **cp);

int			ft_printf(const char *format, ...);
int			ft_fprintf(int stream, const char *format, ...);
int			ft_vfprintf(int stream, const char *format, va_list	ap);
t_obj		*create_obj(void);
size_t		start_parse(const char *format, va_list *ap, \
size_t *bytes_printed, char *buffer);
void		buffer_flush(char buffer[BUFSIZ], int stream);
void		buffer_push_char(char buffer[BUFSIZ], char c);
void		buffer_push_str(char buffer[BUFSIZ], const char *str);
void		buffer_push_int(char buffer[BUFSIZ], int nbr);
size_t		buffer_push_va_list(char buffer[BUFSIZ], const char *format, \
va_list ap);
char		*ptr_to_hex(uintptr_t nbr, int letter_case);
size_t		parse_obj_wrapper(const char *ptr, t_obj *obj);
size_t		parse_flags(const char *ptr, t_obj *obj);
size_t		parse_width(const char *ptr, t_obj *obj);
size_t		parse_precision(const char *ptr, t_obj *obj);
size_t		parse_specifier(const char *ptr, t_obj *obj);
size_t		print_obj(t_obj *obj, va_list *ap, char *buffer);
size_t		print_failed_obj(t_obj *obj, char *buffer);
char		*get_padding_str(t_obj *obj, size_t var_len);
char		*get_precision_str(t_obj *obj, size_t var_len);
size_t		print_char(t_obj *obj, va_list *ap, char *buffer);
size_t		print_str(t_obj *obj, va_list *ap, char *buffer);
size_t		print_ptr(t_obj *obj, va_list *ap, char *buffer);
size_t		print_int(t_obj *obj, va_list *ap, char *buffer);
size_t		print_uint(t_obj *obj, va_list *ap, char *buffer);
size_t		print_hex(t_obj *obj, va_list *ap, int letter_case, char *buffer);
void		str_combine(char **str, ...);

#endif