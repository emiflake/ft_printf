/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_putuns.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 17:52:31 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/31 18:04:28 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "writer.h"
#include "fmt.h"
#include "token.h"
#include <stdarg.h>
#include <stdio.h>

static t_number				va_arg_unsigned_number(t_size size, va_list vlist)
{
	t_number			number;
	unsigned long long	input;

	input = va_arg(vlist, unsigned long long);
	input = intern_auto_floor(size, input);
	number.sign = 1;
	number.value = input;
	number.base = 10U;
	return (number);
}

void						fmt_putuns(
	t_writer *writer,
	t_token *tok,
	va_list vlist)
{
	char		buf[128];
	t_number	n;
	size_t		idx;
	size_t		actual_size;

	intern_pop_wildcards(tok, vlist);
	n = va_arg_unsigned_number(tok->size, vlist);
	idx = intern_ntoa(buf, n, 0);
	actual_size = idx;
	if (tok->flags & FLAGS_PRECISION)
		actual_size = ft_max(idx, tok->precision);
	if (tok->flags & FLAGS_PRECISION && tok->precision < tok->width)
		tok->flags &= ~FLAGS_ZEROPAD;
	intern_fmt_pad_left(writer, tok, intern_pad_char(tok->flags), actual_size);
	if (tok->flags & FLAGS_PRECISION)
		intern_fmt_pad_auto(writer, '0', tok->precision, idx);
	writer_write(writer, buf, idx);
	intern_fmt_pad_right(writer, tok, intern_pad_char(tok->flags), actual_size);
}