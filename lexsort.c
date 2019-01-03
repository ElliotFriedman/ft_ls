/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 23:19:21 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/02 20:57:53 by efriedma         ###   ########.fr       */
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
	
	i = i;
	x = argc;
	while (i < argc)
	{
		int	y = 0;
		int z = i;
		//iterate past all equal characters in adjacent strings
		while (i + 1 < argc && str[i][y] && str[i + 1][y] && str[i + 1][y] == str[i][y])
			y++;
		//go through string z times and while the current string is greater than the next string
		while (z > -1 && z + 1 < argc && str[z + 1][y] < str[z][y])
		{
			//iterate past all equal characters
			while (z + 1 < argc && str[z][y] && str[z + 1][y] && str[z + 1][y] == str[z][y])
				y++;

			//swap the next string with the current string
			tmp = str[z];
			str[z] = str[z + 1];
			str[z + 1] = tmp;
			//go from right to left
			z--;
			y = 0;
		}
		i++;
		int j = 1;
		printf("i: %d\n", i - 1);
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
	int i = 1;
	while (i < argc)
	{
		printf("\n%s\n", argv[i]);
		i++;
	}
	return 0;
}
