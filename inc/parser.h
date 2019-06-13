/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 15:56:15 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/12 14:43:38 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "token.h"

typedef struct	e_char2descriptor
{
	char			c;
	t_descriptor	descriptor;
}				t_char2descriptor;

typedef struct	e_str2size
{
	char*	str;
	t_size	size;
}				t_str2size;

int		parse_atoi(char **stream);
int		parse_atoi_wildcard(char **stream);

#endif
