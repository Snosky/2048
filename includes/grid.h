/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2048.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:17:32 by tpayen            #+#    #+#             */
/*   Updated: 2015/03/01 14:51:47 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <time.h>
# include <ncurses.h>

enum	e_const
{
	WIN_VALUE = 2048
};

typedef struct	s_grid
{
	int	**grid;
	int	size;
}				t_grid;

t_grid			*generate_grid(int grid_size);
void			new_number(t_grid *grid, int force_two);
void			show_grid(t_grid *grid, int w_y, int w_x);
int				move_grid(int ch, t_grid *grid, int *win);
int				is_blocked(t_grid *grid);
int				*try_left(t_grid *grid, int y, int x, int only_space);
int				*try_right(t_grid *grid, int y, int x, int only_space);
int				*try_top(t_grid *grid, int y, int x, int only_space);
int				*try_bottom(t_grid *grid, int y, int x, int only_space);
#endif
