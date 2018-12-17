/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 23:05:55 by efriedma          #+#    #+#             */
/*   Updated: 2018/11/15 22:28:27 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "ft_printf/includes/ft_printf.h"
# include "ft_printf/libft/libft.h"
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# define l 1
# define a 2
# define r 4
# define R 8
# define t 16

const unsigned int		g_opt[256];
short					g_index;
unsigned int			g_flags;

typedef struct			s_file
{
	//boolean for whether or not a string is a directory
	size_t				d;
	//name of file
	char				*name;
	//stat puts out permissions and ownership of a directory
	char				*statformat;

}						t_file;

int						get_opt(int argc, char **argv);

#endif
