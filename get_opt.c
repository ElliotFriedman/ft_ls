/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 23:05:04 by efriedma          #+#    #+#             */
/*   Updated: 2018/07/25 00:39:34 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

const unsigned int	g_opt[256] = {
	['l'] = 1,
	['a'] = 2,
	['r'] = 4,
	['R'] = 8,
	['t'] = 16
};
/*
void	error(int check)
{
	errno = 1;
	ft_printf("%s -- option \'%c\' not found\n", strerror(errno), check);
	//perror();
	exit(errno);
}
*/

int		get_opt(int argc, char **argv)
{
	int		i;
	int		x;
	int		flags;

	i = 1;
	x = 1;
	flags = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-') 
			while (argv[i][x])
			{
				if (!g_opt[(int)argv[i][x]])
				{
					errno = 1;
					ft_printf("%s -- option \'%c\' not found\n", strerror(errno), argv[i][x]);
					exit(errno);
				}
				flags |= g_opt[(int)argv[i][x]];
				//error(argv[i][x]);
				x++;
			}
		i++;
	}
	return (flags);
}
