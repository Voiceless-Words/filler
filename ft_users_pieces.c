/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   users_pieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:54:38 by pragolan          #+#    #+#             */
/*   Updated: 2018/08/07 16:38:33 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_users_pieces(t_filler *node, char *user)
{
	if ((ft_strcmp(user, "p1") == 0))
	{
		node->op_piece = 'X';
		node->my_piece = 'O';
	}
	else
	{
		node->op_piece = 'O';
		node->my_piece = 'X';
	}
}
