/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:15:38 by efriedma          #+#    #+#             */
/*   Updated: 2019/02/06 16:17:04 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//change structure type to do this properly
struct s_node
{
	int value;
	struct s_node *next;
};

//reverse a list in place

void	revList(struct s_node *list)
{
	struct s_node *curr;
	struct s_node *prev;
	struct s_node *next;

	if (!list)
		return ;
	curr = list;
	prev = 0;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
}


