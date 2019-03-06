/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:00:42 by julee             #+#    #+#             */
/*   Updated: 2019/01/06 02:40:10 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	double_freer(char **args)
{
	int		i;

	i = -1;
	while (args[++i] != NULL)
	{
		free(args[i]);
		args[i] = NULL;
	}
	free(args);
	args = NULL;
}

void	str_free(char **line)
{
	free(*line);
	*line = NULL;
}
