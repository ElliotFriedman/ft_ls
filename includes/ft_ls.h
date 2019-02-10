/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 23:05:55 by efriedma          #+#    #+#             */
/*   Updated: 2019/02/09 20:35:44 by efriedma         ###   ########.fr       */
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
# include <dirent.h>
# include <sys/stat.h>

const unsigned int		g_opt[256];
short					g_index;
unsigned int			g_flags;

typedef struct			s_file
{
	char				isvalid;
	char				isdirectory;
	char				*name;
	char				*statformat;
	size_t				len;
	struct s_file		*next;
	struct dirent		*file;
	struct stat			filedata;
}						t_file;

int						get_opt(int argc, char **argv);
t_file					*mergeSort(t_file **ret);

#endif
