/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_squareroot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 10:41:42 by pragolan          #+#    #+#             */
/*   Updated: 2018/08/07 10:41:51 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	ft_squareroot(int num)
{
	int i;
	int result;

	i = 1;
	result = 1;
	if (num == 0 || num == 1)
		return (num);
	while (result <= num)
	{
		i++;
		result = i * i;
	}
	return (i - 1);
}
