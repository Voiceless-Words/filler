/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 15:12:51 by pragolan          #+#    #+#             */
/*   Updated: 2018/08/09 11:23:53 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"

typedef struct		s_filler
{
	int				map_row;
	int				token_row;
	int				map_col;
	int				token_col;
	char			my_piece;
	char			op_piece;
	int				my_row;
	int				op_row;
	int				my_col;
	int				op_col;
	int				token_off_col;
	int				token_off_row;
	char			**map;
	char			**token;
	int				*op_cord;
	int				*my_cord;
	int				h;
	int				l;
	int				*distance;
}					t_filler;

int					ft_squareroot(int num);
void				ft_initialize_variables(t_filler **node1);
void				ft_users_pieces(t_filler *node, char *user);
void				print_grid(char **grid);
int					ft_check_overlap(t_filler *node, int j, int i);
int					ft_try_place(t_filler *node);
char				**ft_get_map(int fd, t_filler *node, char *line);
char				**ft_get_token(int fd, t_filler *node, char *line);
char				**ft_trim_rows(char **token, t_filler *node);
void				ft_print_cordinates(t_filler *node);
int					ft_return_first(char **token, t_filler *node);
#endif
