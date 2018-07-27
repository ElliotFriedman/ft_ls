/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 23:16:41 by efriedma          #+#    #+#             */
/*   Updated: 2018/07/27 00:12:33 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

unsigned int	g_flags;
unsigned int	g_index = 1;

//							-a == hidden flags
//							-l == list files, timestamps, access rights
//							-r == reverse order of the sort
//							-R == recursively list subdirectories
//							-t == sort by time modified. Most recent first

void			ls(char **str)
{
	//If we have to open a directory we will use this
	//and store this in a directory pointer
	//
	//DIR *n;
	//n = opendir(".");

	//iterate past all options, we have already grabbed them
	//
	//if there are no options, just list out files in current directory,
	//so just opendir and then figure out how to store them in a linked list
	//Then print list
	//
	

}


int				main(int argc, char **argv)
{
	//first get all ls options.

	if (argc > 1)
		g_flags = get_opt(argc, argv);
	if (argc > 1 && !g_flags)
		ls(argv);
	else
		ls(argv);
	ft_printf("flags %d\n", g_flags);	

	return 0;
}
