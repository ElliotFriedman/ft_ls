/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 23:16:41 by efriedma          #+#    #+#             */
/*   Updated: 2019/02/06 16:57:37 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

unsigned int	g_flags;
short			g_index = 1;

//							-a == hidden files and directories
//							-l == list files in sorted order by their names in alphabetical order, timestamps, access rights
//							-r == reverse order of the sort
//							-R == recursively list subdirectories
//							-t == sort by time modified. Most recent first

void			ls(char **str)
{
	str = 0;

	//If we have to open a directory we will use this
	//and store this in a directory pointer
	//
	//DIR *n;
	//n = opendir(".");
	
	//check for errors in command line arguments
//	check_err();

	//this will grab all the files for the current flags
//	get_files();

	//order input by flags
//	order_output();
		
	//print out the output
//	print_output();
	
	//free everything
//	free_output();

	//if there are no options, just list out files in current directory,
	//so just opendir and then figure out how to store them in a linked list
	//Then print list
}


int				main(int argc, char **argv)
{
	//first get all ls options.

	if (argc > 1)
	{
		g_flags = get_opt(argc, argv);
		ls(argv);
	}
	ft_printf("flags %d\n", g_flags);	

	return 0;
}
