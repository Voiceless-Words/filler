/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cordinates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:28:48 by pragolan          #+#    #+#             */
/*   Updated: 2018/08/07 16:29:00 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_print_cordinates(t_filler *node)
{
	ft_putnbr(node->my_row - node->token_off_row);
	ft_putchar(' ');
	ft_putnbr(node->my_col - node->token_off_col);
	ft_putchar('\n');
}
