/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opendir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:12:39 by efriedma          #+#    #+#             */
/*   Updated: 2019/02/09 21:24:41 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <dirent.h>

void		printlist(t_file *a)
{
	while (a)
	{
		printf("a: %s\n", a->name);
		a = a->next;
	}
}

void		listlen(t_file *a)
{
	int i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	printf("list len: %d\n", i);
}

void		freelist(t_file *a)
{
	t_file *prev;

	prev = a;
	while (a)
	{
		a = a->next;
		free(prev);
		prev = a;
	}
}

void		findFile(char *path)
{
	DIR *  dirp;
	t_file	*fileList;
	t_file	*head;
	struct dirent		*file;
	int		iter = 0;

	dirp = opendir(path);

	fileList = ft_memalloc(sizeof(t_file));
	head = fileList;
	printf("called findFile\n");
	if (dirp == NULL)
		return ;

	while (1)
	{
		if	((file = readdir(dirp)) != NULL)
		{
			if (iter)
			{
				fileList->next = ft_memalloc(sizeof(t_file));
				fileList = fileList->next;
			}
			fileList->file = file;
			fileList->name = fileList->file->d_name;
			printf("output of lstat: %d\n", lstat(ft_strjoin(path, fileList->file->d_name), &fileList->filedata));
		}
		else
			break;
		iter++;
	}

	fileList = mergeSort(&head);
	printlist(fileList);
	head = fileList;

	while (head)
	{
		printf("in loop: isdir: %d\n", head->filedata.st_mode );
		if (head->filedata.st_mode == S_IFDIR)
			findFile(ft_strjoin( ft_strjoin(path, "/"), head->name));
		head = head->next;
	}
	

	freelist(fileList);
	(void)closedir(dirp);
}

int main()
{
	//	ft_printf("can we find file opendir.c: %s\n", findFile("opendir.c") == 1 ? "yes" : "no");
	//	ft_printf("can we find file opendire.c: %s\n", findFile("opendire.c") == 1 ? "yes" : "no");
	findFile(".");

	return 0;
}
