/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergestring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 01:11:56 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/05 18:41:41 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

typedef struct	s_str
{
	int				len;
	char			*str;
	struct s_str	*next;
}					t_str;

void		printlist(t_str *a)
{
	while (a)
	{
		printf("a: %s\n", a->str);
		a = a->next;
	}
}

t_str* SortedMerge(t_str *a, t_str* b)
{
	t_str* result;

	result = 0;
	if (!a)
		return (b);
	else if (!b)
		return (a);
	if (ft_strcmp(a->str, b->str) < 0)
	{
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return (result);
}

void		frontBackSplit(t_str *head, t_str **a, t_str **b)
{
	t_str	*slow;
	t_str	*fast;

	fast = head->next;
	slow = head;
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			fast = fast->next;
			slow = slow->next;
		}
	}
	*b = slow->next;
	*a = head;
	slow->next = 0;;
}

t_str		*mergeSort(t_str **ret)
{
	t_str	*a;
	t_str	*b;
	t_str	*head;

	a = *ret;
	head = *ret;
	if (!head || !head->next)
		return (0);
	frontBackSplit(head, &a, &b);
	mergeSort(&a);
	mergeSort(&b);
	*ret = SortedMerge(a, b);
	return (*ret);
}

t_str		*buildlist(char **argv, int argc)
{
	t_str	*head;
	t_str	*ret;
	int		i;

	i = 1;
	ret = ft_memalloc(sizeof(t_str));
	head = ret;
	while (i < argc)
	{
		ret->len = (int)ft_strlen(argv[i]);
		ret->str = argv[i];
		if (i + 1 < argc)
			ret->next = ft_memalloc(sizeof(t_str));
		ret = ret->next;
		i++;
	}
	return (head);
}

t_str		*sortedstrings(char **argv, int argc)
{
	t_str	*ret;

	if (argc < 2)
		exit(0);
	ret = buildlist(argv, argc);
	printlist(ret);
	return (mergeSort(&ret));
}

int main(int argc, char **argv)
{
	t_str *sorted = sortedstrings(argv, argc);

	printf("\n\n\n\n\n\n");
	while (sorted)
	{
		printf("%s\n", sorted->str);
		sorted = sorted->next;
	}

	return 0;
}
