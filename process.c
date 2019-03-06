/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:08:37 by julee             #+#    #+#             */
/*   Updated: 2019/02/14 14:04:17 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_functions g_conv[7] = {
	{.pf = &mini_cd, .s = "cd"},
	{.pf = &mini_exit, .s = "exit"},
	{.pf = &mini_echo, .s = "echo"},
	{.pf = &mini_env, .s = "env"},
	{.pf = &mini_setenv, .s = "setenv"},
	{.pf = &mini_unsetenv, .s = "unsetenv"},
	{0, 0}
};

int		exe_cmp(char *exename, char *path)
{
	char	**exelist;
	t_dir	dir;
	int		i;

	exelist = malloc_list(sizeof_dir(path));
	if ((dir.dirp = opendir(path)) == NULL)
		return (0);
	i = -1;
	while ((dir.dp = readdir(dir.dirp)) != NULL)
	{
		if (dir.dp->d_name[0] != '.')
			exelist[++i] = ft_strdup(dir.dp->d_name);
	}
	exelist[i] = NULL;
	closedir(dir.dirp);
	i = -1;
	while (exelist[++i] != NULL)
		if (!ft_strcmp(exelist[i], exename))
			return (1);
	return (0);
}

int		minishell_parser(char **args, char *env)
{
	int		i;
	char	**path;

	path = ft_strsplit(env, ':');
	i = -1;
	while (path[++i] != NULL)
	{
		if (exe_cmp(args[0], path[i]) == 1)
		{
			args[0] = ultimate_strjoin(path[i], "/", args[0]);
			return (1);
		}
	}
	return (0);
}

int		mini_launch(char **args)
{
	pid_t	pid;
	int		status;
	char	*env;

	pid = fork();
	if (pid == 0)
	{
		if ((env = get_env("PATH")) != NULL)
			minishell_parser(args, env);
		if (double_len(args) > 1 && !ft_strcmp(args[1], "~"))
			args[1] = get_env("HOME");
		else if (double_len(args) > 1 && args[1][0] == '~')
			args[1] = ft_strjoin(get_env("HOME"), &args[1][1]);
		if (execve(args[0], args, g_env) == -1 && args[0] != NULL)
		{
			ft_putstr("minishell: command not found: ");
			ft_putendl(args[0]);
		}
		exit(0);
	}
	else if (pid < 0)
		ft_putendl("Error forking");
	else
		wait(&status);
	return (1);
}

int		minishell(char **args)
{
	int		i;

	if (args == NULL || args[0] == NULL)
		return (1);
	i = -1;
	while (g_conv[++i].pf != NULL)
	{
		if (ft_strcmp(args[0], g_conv[i].s) == 0)
			return (g_conv[i].pf(args));
	}
	return (mini_launch(args));
}

void	mini_loop(void)
{
	char	*line;
	char	**args;
	int		status;

	ft_putstr("julee$ ");
	get_next_line(0, &line);
	args = split_line(line);
	status = minishell(args);
	if (line != NULL)
		str_free(&line);
	free(args);
	while (status)
	{
		ft_putstr("julee$ ");
		get_next_line(0, &line);
		args = split_line(line);
		status = minishell(args);
		if (line != NULL)
			str_free(&line);
		free(args);
	}
}
