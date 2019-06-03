/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dprintf.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 15:45:38 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/03 15:46:02 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "writer.h"

ssize_t		ft_vdprintf(int fd, char *fmt, va_list vlist)
{
	t_writer_fd_state	st;
	t_writer			writer;

	st = fd;
	ft_memset(&writer, 0, sizeof(t_writer));
	writer.state = (void*)&st;
	writer.write = &writer_fd_write;
	return (ft_vwprintf(&writer, fmt, vlist));
}

ssize_t		ft_dprintf(int fd, char *fmt, ...)
{
	va_list		vlist;
	ssize_t		ret;

	va_start(vlist, fmt);
	ret = ft_vfprintf(fd, fmt, vlist);
	va_end(vlist);
	return (ret);
}
