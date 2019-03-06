/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 21:44:37 by julee             #+#    #+#             */
/*   Updated: 2019/01/06 03:10:53 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <dirent.h>
# include <stdio.h>

typedef struct		s_dir
{
	DIR				*dirp;
	struct dirent	*dp;
}					t_dir;

typedef struct		s_1
{
	int				(*pf)(char **);
	char			*s;
}					t_functions;

char				**g_env;

int					mini_cd(char **args);
int					mini_echo(char **args);
int					mini_env(char **args);
int					mini_setenv(char **args);
int					mini_unsetenv(char **args);

int					remove_env(char *name);
void				env_copy(char **envp);
char				*get_env(char *name);
int					double_len(char **array);
void				change_env(char *name, char *value);

void				double_freer(char **args);
void				str_free(char **line);

int					mini_launch(char **args);
int					minishell(char **args);
void				mini_loop();

char				*ultimate_strjoin(char *s1, char *s2, char *s3);
int					find_env(char *name);
int					mini_exit(char **args);
char				**realloc_env(int size);
int					is_emptystr(char *line);

char				**split_line(char *line);
char				*ft_strtok(char *str, char *delimiters);

int					sizeof_dir(char *path);
char				**malloc_list(int size);

#endif
