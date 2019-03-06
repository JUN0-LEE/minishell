/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 03:08:03 by julee             #+#    #+#             */
/*   Updated: 2019/01/06 03:36:04 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		sizeof_dir(char *path)
{
	DIR				*dirp;
	struct dirent	*dp;
	int				size;

	if (!(dirp = opendir(path)))
		return (0);
	size = 0;
	while ((dp = readdir(dirp)) != NULL)
		size++;
	closedir(dirp);
	return (size - 1);
}

char	**malloc_list(int size)
{
	char	**exename;

	exename = NULL;
	if (size != 0)
	{
		if (!(exename = (char **)malloc(sizeof(char *) * size)))
			return (NULL);
	}
	else if (size == 0)
		return (NULL);
	return (exename);
}
