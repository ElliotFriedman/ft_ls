/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 23:05:04 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/05 16:02:59 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

# define l 1
# define a 2
# define r 4
# define R 8
# define t 16

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
		if (argv[g_index][0] == '-') 
			while (argv[g_index][x])
			{
				if (!g_opt[(int)argv[g_index][x]])
				{
					errno = 1;
					printf("%s -- option \'%c\' not found\n", strerror(errno), argv[g_index][x]);
					exit(errno);
				}
				flags |= g_opt[(int)argv[g_index][x]];
				x++;
			}
		g_index++;
	}
	return (flags);
}
