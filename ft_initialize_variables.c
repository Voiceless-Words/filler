/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_variables.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:25:17 by pragolan          #+#    #+#             */
/*   Updated: 2018/08/08 17:22:53 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_initialize_variables(t_filler **node1)
{
	t_filler *node;

	node = *node1;
	node->map_row = 0;
	node->token_row = 0;
	node->map_col = 0;
	node->token_off_col = 0;
	node->token_off_row = 0;
	node->token_col = 0;
	node->my_row = 0;
	node->op_row = 0;
	node->op_col = 0;
	node->my_col = 0;
	node->l = 0;
	node->h = 0;
	node->map = NULL;
	node->token = NULL;
	*node1 = node;
}
