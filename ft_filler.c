/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 11:19:22 by pragolan          #+#    #+#             */
/*   Updated: 2018/08/10 13:46:25 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		ft_token_rows(t_filler *node)
{
	int i;

	i = 0;
	while (node->token[i])
		i++;
	return (i);
}

static void		ft_last_one(t_filler *node)
{
	node->my_row = 0;
	node->my_col = 0;
	node->token_off_row = 0;
	node->token_off_col = 0;
	ft_print_cordinates(node);
}

static void		ft_free_variables(t_filler *node)
{
	free(node->token);
	free(node->map);
	free(node->op_cord);
	free(node->my_cord);
	free(node->distance);
}

int				main(void)
{
	t_filler	*node1;
	char		*user;
	char		*line;

	node1 = (t_filler *)ft_memalloc(sizeof(node1));
	get_next_line(0, &line);
	user = ft_strsub(line + 9, 0, 2);
	ft_users_pieces(node1, user);
	while (get_next_line(0, &line))
	{
		ft_initialize_variables(&node1);
		node1->map = ft_get_map(0, node1, line);
		node1->token = ft_get_token(0, node1, line);
		node1->token_col = ft_strlen(node1->token[0]);
		node1->token_row = ft_token_rows(node1);
		if (ft_try_place(node1))
			ft_print_cordinates(node1);
		else
		{
			ft_last_one(node1);
			ft_free_variables(node1);
			return (0);
		}
		ft_free_variables(node1);
	}
}
