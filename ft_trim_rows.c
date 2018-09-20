/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_rows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:57:08 by pragolan          #+#    #+#             */
/*   Updated: 2018/08/10 13:30:22 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char		**ft_assign_values(char **token, int start, int end)
{
	int		i;
	int		j;
	char	**trimmed;

	if (!(trimmed = (char **)ft_memalloc(sizeof(char *) * (end + 50))))
		return (NULL);
	j = 0;
	while (start <= end)
	{
		i = 0;
		while (token[start][i])
		{
			trimmed[j] = ft_strsub(token[start], 0, ft_strlen(token[start]));
			i++;
		}
		j++;
		start++;
	}
	trimmed[j] = NULL;
	return (trimmed);
}

static int	ft_trim_down(char **token)
{
	size_t	i;
	int		j;
	int		flag;

	flag = 0;
	j = 0;
	while (token[j])
		j++;
	j--;
	while (j > 0)
	{
		i = 0;
		while (i < ft_strlen(token[0]))
		{
			if (token[j][i] == '*')
				flag = 1;
			i++;
		}
		if (flag)
			break ;
		j--;
	}
	return (j);
}

char		**ft_trim_rows(char **token, t_filler *node)
{
	int		i;
	int		flag;
	size_t	j;
	int		end;

	flag = 0;
	i = 0;
	while (token[i])
	{
		j = 0;
		while (j < ft_strlen(token[0]))
		{
			if (token[i][j] == '*')
				flag = 1;
			j++;
		}
		if (flag == 1)
			break ;
		i++;
	}
	node->token_off_row = i;
	end = ft_trim_down(token);
	return (ft_assign_values(token, i, end));
}
