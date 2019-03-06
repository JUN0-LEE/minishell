/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:05:55 by julee             #+#    #+#             */
/*   Updated: 2019/01/06 03:55:54 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		mini_setenv(char **args)
{
	int		len;

	if (double_len(args) != 3)
	{
		ft_putendl("setenv: invalid argument :(");
		return (1);
	}
	if (find_env(args[1]) >= 0)
		change_env(args[1], args[2]);
	else if (find_env(args[1]) < 0)
	{
		len = double_len(g_env);
		g_env = realloc_env(len + 1);
		g_env[len] = ultimate_strjoin(args[1], "=", args[2]);
	}
	return (1);
}

int		mini_unsetenv(char **args)
{
	int		len;

	if (double_len(args) != 2)
	{
		ft_putendl("unsetenv: invalid argument :(");
		return (1);
	}
	len = double_len(g_env);
	if (remove_env(args[1]) < 0)
		return (1);
	g_env = realloc_env(len - 1);
	return (1);
}

int		mini_env(char **args)
{
	int		i;

	(void)args;
	i = -1;
	while (g_env[++i] != NULL)
		ft_putendl(g_env[i]);
	return (1);
}

int		mini_echo(char **args)
{
	int		i;

	i = 0;
	while (args[++i] != NULL)
	{
		if (args[i][0] == '$')
		{
			if (get_env(&args[i][1]))
				ft_putendl(get_env(&args[i][1]));
			return (1);
		}
		else if (!ft_strcmp(args[i], "~"))
		{
			ft_putendl(get_env("HOME"));
			return (1);
		}
		ft_putstr(args[i]);
		ft_putchar(' ');
	}
	ft_putchar('\n');
	return (1);
}
