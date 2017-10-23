/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 12:55:45 by aguerin           #+#    #+#             */
/*   Updated: 2017/03/15 12:55:47 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>

int				ft_printf(const char *format, ...);
int				find_conversion(const char *format, va_list va, int *cmp);
int				find(const char *format, int spec[], int *width, int *prec);
int				find_length_modifier(const char *format);
long long		length_modifier_di(int modifier, va_list va);
long long		length_modifier_dou_cap(int modifier, va_list va);
unsigned long	length_modifier_oux(int modifier, va_list va);
void			correction_specifier(int specifier[], int nb, int ox, int d);
char			*adjust(int *width, int *prec, const char *out, int spec[]);
char			*wadjust(int *width, wchar_t *out, int spec[]);
int				print_r(const char *out, int width, int prec, int spec[]);

/*
** src/conversions
*/

int				conversion_s(const char *format, va_list va, int *cmp);
int				conversion_s_cap(const char *format, va_list va, int *cmp);
int				conversion_p(const char *format, va_list va, int *cmp);
int				conversion_d(const char *format, va_list va, int *cmp, char c);
int				conversion_o(const char *format, va_list va, int *cmp, char c);
int				conversion_u(const char *format, va_list va, int *cmp, char c);
int				conversion_x(const char *format, va_list va, int *cmp, char c);
int				conversion_c(const char *format, va_list va, int *cmp);
int				conversion_c_cap(const char *format, va_list va, int *cmp);
int				conversion_percent(const char *format, int *cmp);

#endif
