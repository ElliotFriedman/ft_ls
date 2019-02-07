/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 23:05:55 by efriedma          #+#    #+#             */
/*   Updated: 2019/02/06 16:57:21 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../ft_printf/includes/ft_printf.h"
# include "../ft_printf/libft/libft.h"
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

const unsigned int		g_opt[256];
short					g_index;
unsigned int			g_flags;

typedef struct			s_file
{
	char				isDirectory;
	char				*name;
	char				*statformat;
	struct s_file		*next;

}						t_file;

int						get_opt(int argc, char **argv);

#endif
