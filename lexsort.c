/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 23:19:21 by efriedma          #+#    #+#             */
/*   Updated: 2018/12/17 12:18:23 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


//this  of sort has a time complexity of n^2

//next up lets implement a sorting algorithm that is n log n



//insertion sort O(n^3)
//
//we can do better than this

void	lex_sort(char **str, int argc)
{
	char	*tmp;
	int	i;
	int	x;
	
	i = 0;
	x = argc;
	while (i < argc)
	{
		int	y = 0;
		int z = i;
		while (i + 1 < argc && str[i][y]
				&& str[i + 1][y] && str[i + 1][y] == str[i][y])
			y++;
		while (z > -1 && z + 1 < argc && str[z + 1][y] < str[z][y])
		{
			while (z + 1 < argc && str[z][y]
					&& str[z + 1][y] && str[z + 1][y] == str[z][y])
				y++;
			tmp = str[z];
			str[z] = str[z + 1];
			str[z + 1] = tmp;
			z--;
		}
		i++;
		int j = 1;
		printf("\n");
		while (j < argc)
		{
			printf("%s\n", str[j]);
			j++;
		}
	}
	i = 0;
}

int main(int argc, char **argv)
{
	if (argc > 1)
		lex_sort(argv, argc);
	int i = 0;
	while (i < argc)
	{
		printf("%s\n", argv[i]);
		i++;
	}
	return 0;
}
