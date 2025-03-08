/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colored_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsunwoo <wsunwoo@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:04:46 by wsunwoo           #+#    #+#             */
/*   Updated: 2025/03/08 21:04:02 by wsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static t_cp	cp_global_struct(t_cp *set_static_struct);

int	cp_perror(const char *format, ...)
{
	va_list		ap;
	const t_cp	*cp = cp_global_struct(NULL);

	ft_fprintf(STDERR_FILENO, "%s%s%s", cp->prefix_color, cp->prefix_str, \
	RESET);
	va_start(ap, format);
	ft_fprintf(STDERR_FILENO, cp->text_color);
	ft_vfprintf(STDERR_FILENO, format, ap);
	ft_fprintf(STDERR_FILENO, RESET);
	va_end(ap);
	exit(EXIT_FAILURE);
	return (0);
}

t_cp	*cp_init(const char *prefix_str, const char *prefix_color, \
const char *text_color)
{
	t_cp	*cp;

	cp = (t_cp *)ft_calloc(sizeof(t_cp), 1);
	if (cp == NULL)
	{
		ft_putstr_fd("colored_print: malloc failed\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	cp->prefix_str = prefix_str;
	cp->prefix_color = prefix_color;
	cp->text_color = text_color;
	cp_global_struct(cp);
	return (cp);
}

static t_cp	*cp_global_struct(t_cp *set_static_struct)
{
	static t_cp	*cp_struct;

	if (set_static_struct != NULL)
	{
		free(cp_struct);
		cp_struct = set_static_struct;
	}
	return (cp_struct);
}

void	cp_destroy(t_cp **cp)
{
	free(*cp);
	*cp = NULL;
}
