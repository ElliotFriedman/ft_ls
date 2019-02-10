/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergenameing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 01:11:56 by efriedma          #+#    #+#             */
/*   Updated: 2019/02/09 20:19:36 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_file* SortedMerge(t_file *a, t_file* b)
{
	t_file* result;

	result = 0;
	if (!a)
		return (b);
	else if (!b)
		return (a);
	if (ft_strcmp(a->name, b->name) < 0)
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

void		frontBackSplit(t_file *head, t_file **a, t_file **b)
{
	t_file	*slow;
	t_file	*fast;

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

t_file		*mergeSort(t_file **ret)
{
	t_file	*a;
	t_file	*b;
	t_file	*head;

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

t_file		*buildlist(char **argv, int argc)
{
	t_file	*head;
	t_file	*ret;
	int		i;

	i = 1;
	ret = ft_memalloc(sizeof(t_file));
	head = ret;
	while (i < argc)
	{
		ret->len = (int)ft_strlen(argv[i]);
		ret->name = argv[i];
		if (i + 1 < argc)
			ret->next = ft_memalloc(sizeof(t_file));
		ret = ret->next;
		i++;
	}
	return (head);
}

t_file		*sortList(t_file *ret)//char **argv, int argc)
{
/*
	if (argc < 2)
		exit(0);
	ret = buildlist(argv, argc);

	printlist(ret);
*/
	return (mergeSort(&ret));
}

