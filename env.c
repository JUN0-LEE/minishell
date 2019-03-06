/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:03:22 by julee             #+#    #+#             */
/*   Updated: 2019/01/06 02:44:26 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		remove_env(char *name)
{
	int		i;

	if ((i = find_env(name)) < 0)
		return (-1);
	str_free(&g_env[i]);
	while (g_env[i + 1] != NULL)
	{
		g_env[i] = ft_strdup(g_env[i + 1]);
		str_free(&g_env[i + 1]);
		i++;
	}
	return (1);
}

int		double_len(char **array)
{
	int		len;

	len = 0;
	while (array[len] != NULL)
		len++;
	return (len);
}

void	env_copy(char **envp)
{
	int		i;
	int		len;

	len = 0;
	while (envp[len] != NULL)
		len++;
	g_env = (char **)malloc(sizeof(char *) * (len + 1));
	g_env[len] = NULL;
	i = -1;
	while (envp[++i] != NULL)
		g_env[i] = ft_strdup(envp[i]);
}

char	*get_env(char *name)
{
	int		i;
	int		j;
	char	*var;

	if ((i = find_env(name)) < 0)
		return (NULL);
	j = 0;
	while (g_env[i][j] != '=' && g_env[i][j] != '\0')
		j++;
	var = ft_strdup(&g_env[i][j + 1]);
	return (var);
}

char	**realloc_env(int size)
{
	char	**new;
	int		i;

	if (!(new = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	new[size] = NULL;
	i = -1;
	while (g_env[++i] && i < size)
		new[i] = ft_strdup(g_env[i]);
	double_freer(g_env);
	return (new);
}
