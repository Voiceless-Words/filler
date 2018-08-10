/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_overlap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 16:40:37 by pragolan          #+#    #+#             */
/*   Updated: 2018/08/08 17:38:16 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_check_token(int row, int *k, int count, t_filler *node)
{
	while (*k < node->map_col && node->h < node->token_col)
	{
		if (node->map[row][*k] == node->my_piece)
		{
			if (node->token[node->l][node->h] == '*')
				count++;
		}
		else if (node->map[row][*k] == node->op_piece)
		{
			if (node->token[node->l][node->h] == '*')
			{
				count = 2;
				break ;
			}
		}
		*k += 1;
		node->h++;
	}
	return (count);
}

static int	ft_check_valid(int i, int j, t_filler *node, int count)
{
	int k;
	int row;

	row = i;
	node->l = 0;
	while (row < node->map_row && node->l < node->token_row)
	{
		node->h = 0;
		k = j;
		count = ft_check_token(row, &k, count, node);
		if (count == 2)
			break ;
		row++;
		node->l++;
	}
	if (count == 1 && row <= node->map_row && k <= node->map_col\
			&& node->h == node->token_col && node->l == node->token_row)
		return (1);
	return (0);
}

int			ft_check_overlap(t_filler *node, int col, int row)
{
	int count;

	count = 0;
	if (ft_check_valid(row, col, node, count))
		return (1);
	return (0);
}
