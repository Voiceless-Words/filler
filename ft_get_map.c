/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 12:11:30 by pragolan          #+#    #+#             */
/*   Updated: 2018/08/07 16:19:10 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	**ft_get_map(int fd, t_filler *node, char *line)
{
	int		i;
	char	**map;

	map = NULL;
	i = 0;
	node->map_row = ft_atoi(line + 8);
	node->map_col = ft_atoi(ft_strchr(line + 8, ' ') + 1);
	if (!map)
	{
		if (!(map = (char **)ft_memalloc(sizeof(char *) * (node->map_row + 1))))
			return (0);
	}
	get_next_line(fd, &line);
	while (i < node->map_row)
	{
		get_next_line(fd, &line);
		map[i] = ft_strsub(line + 4, 0, ft_strlen(line) - 4);
		i++;
	}
	map[i] = NULL;
	return (map);
}
