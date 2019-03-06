/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 02:55:45 by julee             #+#    #+#             */
/*   Updated: 2019/02/14 14:00:44 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char				*g_sp = NULL;

char	**split_line(char *line)
{
	int		bufsize;
	int		position;
	char	**tokens;
	char	*token;

	bufsize = 64;
	position = 0;
	tokens = malloc(bufsize * sizeof(char*));
	if (!tokens)
		return (NULL);
	token = ft_strtok(line, "\" \t");
	while (token != NULL)
	{
		tokens[position++] = token;
		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char*));
			if (!tokens)
				return (NULL);
		}
		token = ft_strtok(NULL, "\" \t");
	}
	tokens[position] = NULL;
	return (tokens);
}

void	ft_strtok_loop(char **start, char *delimiters)
{
	int		i;

	while (1)
	{
		i = -1;
		while (++i < 3)
		{
			if (**start == delimiters[i])
			{
				(*start)++;
				break ;
			}
		}
		if (i == 3)
		{
			g_sp = *start;
			break ;
		}
	}
}

void	ft_strtok2(char *delimiters)
{
	int		i;

	while (*g_sp != '\0')
	{
		i = -1;
		while (++i < 3)
		{
			if (*g_sp == delimiters[i])
			{
				*g_sp = '\0';
				break ;
			}
		}
		g_sp++;
		if (i < 3)
			break ;
	}
}

char	*ft_strtok(char *str, char *delimiters)
{
	char	*p_start;

	if (!str && !g_sp)
		return (NULL);
	if (str && !g_sp)
		g_sp = str;
	p_start = g_sp;
	ft_strtok_loop(&p_start, delimiters);
	if (*g_sp == '\0')
	{
		g_sp = NULL;
		return (g_sp);
	}
	ft_strtok2(delimiters);
	return (p_start);
}
