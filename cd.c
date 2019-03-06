/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 03:53:34 by julee             #+#    #+#             */
/*   Updated: 2019/03/06 12:26:21 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mini_cd2(char **args, char *home, char *cwd)
{
	char	*path;

	if (double_len(args) != 2)
	{
		ft_putendl("too many arguments! :(");
		return ;
	}
	if (!ft_strcmp(args[1], "-"))
		args[1] = get_env("OLDPWD");
	if (!ft_strcmp(args[1], "~"))
		args[1] = ft_strdup(home);
	else if (args[1][0] == '~')
		args[1] = ft_strjoin(home, &args[1][1]);
	else if (args[1][0] == '$' && (path = get_env(&args[1][1])))
		args[1] = path;
	if (chdir(args[1]) != 0)
	{
		ft_putstr("cd : no such file or directory: ");
		ft_putendl(args[1]);
	}
	else
		change_env("OLDPWD", cwd);
}

int		mini_cd(char **args)
{
	char	*cwd;
	char	*path;
	char	*home;
	char	*buff;

	path = NULL;
	buff = NULL;
	cwd = getcwd(buff, 0);
	home = get_env("HOME");
	if (args[1] == NULL)
	{
		if (chdir(home) != 0)
			ft_putendl("Error");
		else
			change_env("OLDPWD", cwd);
		free(path);
	}
	else
		mini_cd2(args, home, cwd);
	return (1);
}
