/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergestring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 01:11:56 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/03 01:57:26 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

typedef struct	s_str
{
	int				len;
	char			*str;
	struct s_str	*next;
}					t_str;

int			listlen(t_str *ret)
{
	int		i;

	i = 0;
	while (ret)
	{
		ret = ret->next;
		i++;
	}
	return (i);
}

//merge everything into a
void		merge(t_str **a, t_str **b)
{
	int		cmp;
	//implement these two
	t_str	*head;
	t_str	*ret;


	if (!(cmp = ft_strcmp((*a)->str, (*b)->str)))
	{

	}
	else if ((*a)->len == (*b)->len)
	{

	}
	else
	{
		//just lost reference to the current head of a, need another pointer
		(*a)->next = cmp > 0 ? (*a)->next : (*b)->next;
		//now we just lost reference to this value we set
		*a = (*a)->next;
	}

	*a = head;
}

t_str		*mergesort(t_str **ret)
{
	//split linked list into two halves
	t_str	*a;
	t_str	*b;
	int		len;

	len = listlen(*ret);
	a = *ret;
	//	b = split(ret);
	if (!*ret || len == 1)
		return ;

	len /= 2;

	while (len)
	{
		a = a->next;
		len--;
	}
	b = a->next;
	a->next = 0;
	mergesort(&ret);
	mergesort(&b);
	merge(&ret, &b);
}

void		addvalues(t_str *ret, char **argv, int argc)
{
	int i;

	i = 1;
	while (i < argc)
	{
		ret->len = (int)ft_strlen(argv[i]);
		ret->str = argv[i];
		i++;
	}
}

void		buildlist(t_str **ret, int argc)
{
	argc -= 2;
	(*ret) = ft_memmalloc(sizeof(t_str));
	while (argc > 0)
	{
		(*ret)->next = ft_memmalloc(sizeof(t_str));
		(*ret) = (*ret)->next;
		argc--;
	}
}

t_str		*sortedstrings(char **argv, int argc)
{
	t_str	*ret;

	if (argc < 2)
		exit();
	buildlist(&ret, argc);
	//build the list
	//
	//add values
	//
	addvalues(ret, argv, argc);
	//
	//sort
	return (mergesort(ret));
	//
	//return

}
