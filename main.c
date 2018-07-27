/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 23:16:41 by efriedma          #+#    #+#             */
/*   Updated: 2018/07/26 22:09:15 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

unsigned int	g_flags;

//							-a == hidden flags
//							-l == list files, timestamps, access rights
//							-r == reverse order of the sort
//							-R == recursively list subdirectories
//							-t == sort by time modified. Most recent first


int				main(int argc, char **argv)
{
	//first get all ls options.

	if (argc > 1)
		g_flags = get_opt(argc, argv);
	
	
	ft_printf("flags %d\n", g_flags);	

	return 0;
}
