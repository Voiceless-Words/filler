/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 17:22:51 by pragolan          #+#    #+#             */
/*   Updated: 2018/08/08 12:27:04 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_check_cord(t_filler *node)
{
	int j;
	int l;
	int dist;

	dist = 0;
	j = node->my_cord[0] - node->op_cord[0];
	l = node->my_cord[1] - node->op_cord[1];
	dist = ft_squareroot((j * j) + (l * l));
	if (node->distance[0] == -1)
		node->distance[0] = dist;
	if (dist < node->distance[0])
		node->distance[0] = dist;
}

static void		ft_check_close(t_filler *node)
{
	int i;
	int j;

	i = 0;
	while (i < node->map_row)
	{
		j = 0;
		while (j < node->map_col)
		{
			if (node->map[i][j] == node->op_piece)
			{
				node->op_cord[0] = i;
				node->op_cord[1] = j;
				ft_check_cord(node);
			}
			j++;
		}
		i++;
	}
}

static void		ft_assign(t_filler *node)
{
	ft_check_close(node);
	if (node->distance[1] == -1)
	{
		node->my_row = node->my_cord[0];
		node->my_col = node->my_cord[1];
		node->distance[1] = node->distance[0];
	}
	if (node->distance[0] < node->distance[1])
	{
		node->my_row = node->my_cord[0];
		node->my_col = node->my_cord[1];
		node->distance[1] = node->distance[0];
	}
}

static void		ft_init(t_filler *node)
{
	node->my_cord = (int *)malloc(sizeof(int) * 2);
	node->my_cord[0] = 0;
	node->my_cord[1] = 0;
	node->op_cord = (int *)malloc(sizeof(int) * 2);
	node->op_cord[0] = 0;
	node->op_cord[1] = 0;
	node->distance = (int *)malloc(sizeof(int) * 2);
	node->distance[0] = -1;
	node->distance[1] = -1;
}

int				ft_try_place(t_filler *node)
{
	int i;
	int j;
	int count;

	count = 0;
	i = 0;
	ft_init(node);
	while (i < node->map_row)
	{
		j = 0;
		while (j < node->map_col)
		{
			if (ft_check_overlap(node, j, i))
			{
				node->my_cord[0] = i;
				node->my_cord[1] = j;
				count = 1;
				ft_assign(node);
			}
			j++;
		}
		i++;
	}
	return ((count == 1) ? 1 : 0);
}
