/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 20:18:14 by julee             #+#    #+#             */
/*   Updated: 2019/01/06 02:38:59 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		find_env(char *name)
{
	int		len;
	int		i;

	len = ft_strlen(name);
	i = -1;
	while (g_env[++i] != NULL)
		if (ft_strncmp(g_env[i], name, len) == 0)
			return (i);
	return (-1);
}

char	*ultimate_strjoin(char *s1, char *s2, char *s3)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_strjoin(s1, s2);
	tmp2 = ft_strjoin(tmp1, s3);
	free(tmp1);
	tmp1 = NULL;
	return (tmp2);
}

int		is_emptystr(char *line)
{
	int		i;

	if (line == NULL || !*line)
		return (1);
	i = -1;
	while (line[++i])
	{
		if (33 <= line[i] && line[i] <= 126)
			return (0);
	}
	return (1);
}

int		mini_exit(char **args)
{
	(void)args;
	return (0);
}

void	change_env(char *name, char *value)
{
	int		i;

	if ((i = find_env(name)) < 0)
		return ;
	if (g_env[i])
	{
		str_free(&g_env[i]);
		g_env[i] = ultimate_strjoin(name, "=", value);
	}
}
