/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 23:05:04 by efriedma          #+#    #+#             */
/*   Updated: 2019/02/06 16:57:48 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
# define l 1
# define a 2
# define r 4
# define R 8
# define t 16
*/

const unsigned int	g_opt[256] = {
	['l'] = 1,
	['a'] = 2,
	['r'] = 4,
	['R'] = 8,
	['t'] = 16
};

int		get_opt(int argc, char **argv)
{
	int		x;
	int		flags;

	x = 1;
	flags = 0;
	while (g_index < argc)
	{
		x = 1;
		if (!ft_strcmp(argv[g_index], "--"))
				return flags;
		if (argv[g_index][0] == '-') 
			while (argv[g_index][x])
			{
				if (!g_opt[(int)argv[g_index][x]])
				{
					errno = 1;
					ft_printf("%s -- option \'%c\' not found\n", strerror(errno), argv[g_index][x]);
					exit(errno);
				}
				flags |= g_opt[(int)argv[g_index][x]];
				x++;
			}
		else
			return (flags);
		g_index++;
	}
	return (flags);
}
