/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ansi_colors.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsunwoo <wsunwoo@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 02:18:43 by wsunwoo           #+#    #+#             */
/*   Updated: 2025/03/08 21:03:06 by wsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANSI_COLORS_H
# define ANSI_COLORS_H

# ifdef _READLINE_H_ /* for terminal cursor / buffer control uses SOH and STX */
#  define SOH "\001" /* Start of header */
#  define STX "\002" /* Start of text */
#  define ANSI_ESC_RESET "\001\033[0m\002"

#  define ANSI_ESC_RED "\001\033[31m\002"
#  define ANSI_ESC_BOLD_RED "\001\033[1;31m\002"
#  define ANSI_ESC_ITALIC_RED "\001\033[3;31m\002"
#  define ANSI_ESC_BOLD_ITALIC_RED "\001\033[1;3;31m\002"

#  define ANSI_ESC_GREEN "\001\033[32m\002"
#  define ANSI_ESC_BOLD_GREEN "\001\033[1;32m\002"
#  define ANSI_ESC_ITALIC_GREEN "\001\033[3;32m\002"
#  define ANSI_ESC_BOLD_ITALIC_GREEN "\001\033[1;3;32m\002"

#  define ANSI_ESC_YELLOW "\001\033[33m\002"
#  define ANSI_ESC_BOLD_YELLOW "\001\033[1;33m\002"
#  define ANSI_ESC_ITALIC_YELLOW "\001\033[3;33m\002"
#  define ANSI_ESC_BOLD_ITALIC_YELLOW "\001\033[1;3;33m\002"

#  define ANSI_ESC_BLUE "\001\033[34m\002"
#  define ANSI_ESC_BOLD_BLUE "\001\033[1;34m\002"
#  define ANSI_ESC_ITALIC_BLUE "\001\033[3;34m\002"
#  define ANSI_ESC_BOLD_ITALIC_BLUE "\001\033[1;3;34m\002"

#  define ANSI_ESC_MAGENTA "\001\033[35m\002"
#  define ANSI_ESC_BOLD_MAGENTA "\001\033[1;35m\002"
#  define ANSI_ESC_ITALIC_MAGENTA "\001\033[3;35m\002"
#  define ANSI_ESC_BOLD_ITALIC_MAGENTA "\001\033[1;3;35m\002"

#  define ANSI_ESC_CYAN "\001\033[36m\002"
#  define ANSI_ESC_BOLD_CYAN "\001\033[1;36m\002"
#  define ANSI_ESC_ITALIC_CYAN "\001\033[3;36m\002"
#  define ANSI_ESC_BOLD_ITALIC_CYAN "\001\033[1;3;36m\002"

#  define ANSI_ESC_WHITE "\001\033[37m\002"
#  define ANSI_ESC_BOLD_WHITE "\001\033[1;37m\002"
#  define ANSI_ESC_ITALIC_WHITE "\001\033[3;37m\002"
#  define ANSI_ESC_BOLD_ITALIC_WHITE "\001\033[1;3;37m\002"

#  define ANSI_ESC_BOLD "\001\033[1m\002"
#  define ANSI_ESC_ITALIC "\001\033[3m\002"
#  define ANSI_ESC_BOLD_ITALIC "\001\033[1;3m\002"

# else /* default */
#  define ANSI_ESC_RESET "\033[0m"

#  define ANSI_ESC_RED "\033[31m"
#  define ANSI_ESC_BOLD_RED "\033[1;31m"
#  define ANSI_ESC_ITALIC_RED "\033[3;31m"
#  define ANSI_ESC_BOLD_ITALIC_RED "\033[1;3;31m"

#  define ANSI_ESC_GREEN "\033[32m"
#  define ANSI_ESC_BOLD_GREEN "\033[1;32m"
#  define ANSI_ESC_ITALIC_GREEN "\033[3;32m"
#  define ANSI_ESC_BOLD_ITALIC_GREEN "\033[1;3;32m"

#  define ANSI_ESC_YELLOW "\033[33m"
#  define ANSI_ESC_BOLD_YELLOW "\033[1;33m"
#  define ANSI_ESC_ITALIC_YELLOW "\033[3;33m"
#  define ANSI_ESC_BOLD_ITALIC_YELLOW "\033[1;3;33m"

#  define ANSI_ESC_BLUE "\033[34m"
#  define ANSI_ESC_BOLD_BLUE "\033[1;34m"
#  define ANSI_ESC_ITALIC_BLUE "\033[3;34m"
#  define ANSI_ESC_BOLD_ITALIC_BLUE "\033[1;3;34m"

#  define ANSI_ESC_MAGENTA "\033[35m"
#  define ANSI_ESC_BOLD_MAGENTA "\033[1;35m"
#  define ANSI_ESC_ITALIC_MAGENTA "\033[3;35m"
#  define ANSI_ESC_BOLD_ITALIC_MAGENTA "\033[1;3;35m"

#  define ANSI_ESC_CYAN "\033[36m"
#  define ANSI_ESC_BOLD_CYAN "\033[1;36m"
#  define ANSI_ESC_ITALIC_CYAN "\033[3;36m"
#  define ANSI_ESC_BOLD_ITALIC_CYAN "\033[1;3;36m"

#  define ANSI_ESC_WHITE "\033[37m"
#  define ANSI_ESC_BOLD_WHITE "\033[1;37m"
#  define ANSI_ESC_ITALIC_WHITE "\033[3;37m"
#  define ANSI_ESC_BOLD_ITALIC_WHITE "\033[1;3;37m"

#  define ANSI_ESC_BOLD "\033[1m"
#  define ANSI_ESC_ITALIC "\033[3m"
#  define ANSI_ESC_BOLD_ITALIC "\033[1;3m"

# endif /* _READLINE_H_ */

/* Shorter aliases for convenience */
# define RESET ANSI_ESC_RESET

# define RED ANSI_ESC_RED
# define B_RED ANSI_ESC_BOLD_RED
# define I_RED ANSI_ESC_ITALIC_RED
# define BI_RED ANSI_ESC_BOLD_ITALIC_RED

# define GREEN ANSI_ESC_GREEN
# define B_GREEN ANSI_ESC_BOLD_GREEN
# define I_GREEN ANSI_ESC_ITALIC_GREEN
# define BI_GREEN ANSI_ESC_BOLD_ITALIC_GREEN

# define YELLOW ANSI_ESC_YELLOW
# define B_YELLOW ANSI_ESC_BOLD_YELLOW
# define I_YELLOW ANSI_ESC_ITALIC_YELLOW
# define BI_YELLOW ANSI_ESC_BOLD_ITALIC_YELLOW

# define BLUE ANSI_ESC_BLUE
# define B_BLUE ANSI_ESC_BOLD_BLUE
# define I_BLUE ANSI_ESC_ITALIC_BLUE
# define BI_BLUE ANSI_ESC_BOLD_ITALIC_BLUE

# define MAGENTA ANSI_ESC_MAGENTA
# define B_MAGENTA ANSI_ESC_BOLD_MAGENTA
# define I_MAGENTA ANSI_ESC_ITALIC_MAGENTA
# define BI_MAGENTA ANSI_ESC_BOLD_ITALIC_MAGENTA

# define CYAN ANSI_ESC_CYAN
# define B_CYAN ANSI_ESC_BOLD_CYAN
# define I_CYAN ANSI_ESC_ITALIC_CYAN
# define BI_CYAN ANSI_ESC_BOLD_ITALIC_CYAN

# define WHITE ANSI_ESC_WHITE
# define B_WHITE ANSI_ESC_BOLD_WHITE
# define I_WHITE ANSI_ESC_ITALIC_WHITE
# define BI_WHITE ANSI_ESC_BOLD_ITALIC_WHITE

# define BOLD ANSI_ESC_BOLD
# define ITALIC ANSI_ESC_ITALIC
# define BOLD_ITALIC ANSI_ESC_BOLD_ITALIC

#endif /* ANSI_COLORS_H */
