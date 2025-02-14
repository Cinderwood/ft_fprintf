/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsunwoo <wsunwoo@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 03:44:48 by wsunwoo           #+#    #+#             */
/*   Updated: 2025/02/14 22:22:25 by wsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static char	*get_ptr_sign(t_obj *obj)
{
	if (obj->flag_plus == true)
		return (ft_strdup("+"));
	if (obj->flag_space == true)
		return (ft_strdup(" "));
	return (ft_strdup(""));
}

static void	free_strs(char *s1, char *s2, char *s3, char*s4)
{
	free(s1);
	free(s2);
	free(s3);
	free(s4);
}

static void	print_ptr_rules(char *strs[4], int minus, int zero, char *buffer)
{
	char	*str;

	str = ft_strdup("");
	if (str == NULL)
		return ;
	if (minus == true)
	{
		if (zero == true)
			ft_memset(strs[3], ' ', ft_strlen(strs[3]));
		str_combine(&str, strs[2], strs[1], strs[0], strs[3], NULL);
	}
	else if (minus == false)
	{
		if (zero == true)
		{
			str_combine(&str, strs[2], strs[1], strs[3], strs[0], NULL);
		}
		else if (zero == false)
		{
			str_combine(&str, strs[3], strs[2], strs[1], strs[0], NULL);
		}
	}
	buffer_push_str(buffer, str);
	free (str);
}

size_t	print_ptr(t_obj *obj, va_list *ap, char *buffer)
{
	void	*ptr;
	char	*strs[4];
	size_t	bytes_printed;

	ptr = va_arg(*ap, void *);
	if (ptr == NULL)
	{
		strs[0] = ft_strdup("(nil)");
		strs[1] = ft_strdup("");
		strs[2] = ft_strdup("");
	}
	else
	{
		strs[0] = ptr_to_hex((uintptr_t)ptr, false);
		strs[1] = ft_strdup(L_PREFIX);
		strs[2] = get_ptr_sign(obj);
	}
	strs[3] = get_padding_str(obj, ft_strlen(strs[0]) + ft_strlen(strs[1]));
	print_ptr_rules(strs, obj->flag_minus, obj->flag_zero, buffer);
	bytes_printed = ft_strlen(strs[0]) + ft_strlen(strs[1]) \
	+ ft_strlen(strs[2]) + ft_strlen(strs[3]);
	free_strs(strs[0], strs[1], strs[2], strs[3]);
	return (bytes_printed);
}
