/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_first.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:59:23 by pragolan          #+#    #+#             */
/*   Updated: 2018/08/08 17:03:51 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_return_first(char **token, t_filler *node)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = 0;
	temp = 0;
	while (i < node->token_row)
	{
		j = 0;
		while (token[i][j] != '*' && j < node->token_col)
			j++;
		if (token[i][j] == '*')
		{
			temp = j;
			break ;
		}
		i++;
	}
	return (temp);
}
