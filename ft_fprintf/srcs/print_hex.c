/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsunwoo <wsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 00:58:41 by wsunwoo           #+#    #+#             */
/*   Updated: 2024/12/12 19:16:46 by wsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static char	*get_hex_prefix(t_obj *obj, char *s)
{
	char	*str;

	if (!ft_strncmp(s, "0", 2) || !ft_strncmp(s, "", 1))
		str = ft_strdup("");
	else if (obj->var_type == 'x' && obj->flag_hash == TRUE)
		str = ft_strdup(L_PREFIX);
	else if (obj->var_type == 'X' && obj->flag_hash == TRUE)
		str = ft_strdup(U_PREFIX);
	else
		str = ft_strdup("");
	return (str);
}

static void	print_hex_rules(t_obj *obj, char *strs[4], char *buffer)
{
	char	*str;

	str = ft_strdup("");
	if (str == NULL)
		return ;
	if (obj->flag_minus == TRUE && obj->flag_zero == TRUE)
		str_combine(&str, strs[1], strs[2], strs[0], strs[3], NULL);
	else if (obj->flag_minus == TRUE && obj->flag_zero == FALSE)
		str_combine(&str, strs[1], strs[2], strs[0], strs[3], NULL);
	else if (obj->flag_minus == FALSE && obj->flag_zero == TRUE)
		str_combine(&str, strs[3], strs[1], strs[2], strs[0], NULL);
	else if (obj->flag_minus == FALSE && obj->flag_zero == FALSE)
		str_combine(&str, strs[3], strs[1], strs[2], strs[0], NULL);
	buffer_push_str(buffer, str);
	free(str);
}

size_t	print_hex(t_obj *obj, va_list *ap, int letter_case, char *buffer)
{
	char	*strs[4];
	size_t	bytes_printed;

	strs[0] = ptr_to_hex(va_arg(*ap, unsigned int), letter_case);
	if (!ft_strncmp(strs[0], "0", 2) && obj->precision_true == TRUE \
	&& obj->precision_num == 0)
	{
		free(strs[0]);
		strs[0] = ft_strdup("");
	}
	strs[1] = get_hex_prefix(obj, strs[0]);
	strs[2] = get_precision_str(obj, ft_strlen(strs[0]));
	strs[3] = get_padding_str(obj, ft_strlen(strs[0]) \
	+ ft_strlen(strs[1]) + ft_strlen(strs[2]));
	print_hex_rules(obj, strs, buffer);
	bytes_printed = ft_strlen(strs[0]) + ft_strlen(strs[1]) \
	+ ft_strlen(strs[2]) + ft_strlen(strs[3]);
	free(strs[0]);
	free(strs[1]);
	free(strs[2]);
	free(strs[3]);
	return (bytes_printed);
}
