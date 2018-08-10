/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 13:26:27 by pragolan          #+#    #+#             */
/*   Updated: 2018/08/08 17:13:49 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char		**ft_assign_values(char **token, int row, int start, int end)
{
	char	**token1;
	int		i;

	i = 0;
	if (!(token1 = (char **)ft_memalloc(sizeof(char *) * (row + 2))))
		return (NULL);
	while (token[i])
	{
		token1[i] = ft_strsub(token[i], start, end + 1);
		i++;
	}
	token1[i] = NULL;
	return (token1);
}

static int		ft_get_last(t_filler *node, char **token)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = 0;
	temp = 0;
	while (i < node->token_row)
	{
		j = ft_strlen(token[0]) - 1;
		while (token[i][j] != '*' && j >= 0)
			j--;
		if (token[i][j] == '*')
		{
			temp = j;
			break ;
		}
		i++;
	}
	return (temp);
}

static char		**ft_trim_ends(char **token, t_filler *node)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = 0;
	temp = ft_get_last(node, token);
	while (i < node->token_row)
	{
		j = ft_strlen(token[0]) - 1;
		while (token[i][j] != '*' && j >= 0)
			j--;
		if (j >= temp && token[i][j] == '*')
			temp = j;
		i++;
	}
	return (ft_trim_rows(ft_assign_values(token, i, 0, temp), node));
}

static char		**ft_trim_token(t_filler *node, char **token)
{
	int		i;
	int		j;
	int		temp;
	char	**str;

	i = 0;
	j = 0;
	temp = ft_return_first(token, node);
	while (i < node->token_row)
	{
		j = 0;
		while (token[i][j] != '*' && j < node->token_col)
			j++;
		if (j <= temp && token[i][j] == '*')
			temp = j;
		i++;
	}
	node->token_off_col = temp;
	str = ft_assign_values(token, i, temp, (ft_strlen(token[0]) - temp));
	return (ft_trim_ends(str, node));
}

char			**ft_get_token(int fd, t_filler *node, char *line)
{
	int		i;
	char	**token;

	i = 0;
	get_next_line(fd, &line);
	node->token_row = ft_atoi(line + 6);
	node->token_col = ft_atoi(ft_strchr(line + 6, ' ') + 1);
	if (!(token = (char **)ft_memalloc(sizeof(char *) * (node->token_row + 1))))
		return (0);
	while (i < node->token_row)
	{
		get_next_line(fd, &line);
		token[i] = line;
		i++;
	}
	token[i] = NULL;
	return (ft_trim_token(node, token));
}
