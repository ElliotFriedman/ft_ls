/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergestring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 01:11:56 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/05 16:14:30 by efriedma         ###   ########.fr       */
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

//merge everything into ret
t_str		*merge(t_str *a, t_str *b)
{
	int		cmp;
	//implement these two
	t_str	*head;
	t_str	*ret;

	//find the first string and set your head to it
	head = ft_strcmp(a->str, b->str) < 0 ? a : b;
	a = ft_strcmp(a->str, b->str) < 0 ? a->next : a;
	b = ft_strcmp(a->str, b->str) > 0 ? b->next : b;
	ret = head;
	while (42)
	{
		printf("Merging: a %s b %s\n", a->str, b->str);
		if (a == 0 && b == 0)
			return (ret);
		//check if the strings of a and b match up, cmp will be 0 if so
		if (!(cmp = ft_strcmp(a->str, b->str)))
		{
			head->next = cmp < 0 ? a : b;
			a->next = cmp < 0 ? a->next : a;
			b->next = cmp > 0 ? b->next : b;
		}
		//if the strings are equal, then what do we do?
		if (!cmp)
		{
			//set next value to a
			head->next = a ? a : b;
			//set a to the next value otherwise it is already 0
			a = a ? a->next : 0;
			//if there wasn't a value at a, iterate b
			b = !a ? b->next : b;
		}
		printf("Merging: head %s\n", head->str);	
		head = head->next;
	}
	return (ret);
}

t_str		*mergeSort(t_str **ret)
{
	//split linked list into two halves
	t_str	*a;
	t_str	*b;
	int		len;

	len = listlen(*ret);
	a = *ret;
	//	b = split(ret);
	printf("Ret value: %s\n", (*ret)->str);
	if (!*ret || len == 1)
		return (0);
	len /= 2;
	while (len)
	{
		a = a->next;
		len--;
	}
	b = a->next;
	a->next = 0;
	mergeSort(ret);
	mergeSort(&b);
	*ret = merge(*ret, b);
	return (*ret);
}

void		addvalues(t_str *ret, char **argv, int argc)
{
	int i;

	i = 1;
	while (i < argc)
	{
		ret->len = (int)ft_strlen(argv[i]);
		ret->str = argv[i];
		printf("%s\n", argv[i]);
		i++;
	}
}

void		buildlist(t_str **ret, int argc)
{
	argc -= 2;
	(*ret) = ft_memalloc(sizeof(t_str));
	while (argc > 0)
	{
		(*ret)->next = ft_memalloc(sizeof(t_str));
		(*ret) = (*ret)->next;
		argc--;
	}
}

t_str		*sortedstrings(char **argv, int argc)
{
	t_str	*ret;

	if (argc < 2)
		exit(0);
	buildlist(&ret, argc);
	addvalues(ret, argv, argc);
	return (mergeSort(&ret));
}

int main(int argc, char **argv)
{
	t_str *sorted = sortedstrings(argv, argc);

	while (sorted)
	{
		printf("%s\n", sorted->str);
		sorted = sorted->next;
	}

	return 0;
}
