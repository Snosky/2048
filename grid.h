/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2048.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:17:32 by tpayen            #+#    #+#             */
/*   Updated: 2015/02/28 22:10:47 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H
# include "libft/libft.h"
# include <stdlib.h>
# include <time.h>
# include <ncurses.h>

enum	e_const
{
	WIN_VALUE = 2048
};

int		**generate_grid(int grid_size);
void	new_number(int **grid, int grid_size, int force_two);
void	show_grid(int **grid, int grid_size, int w_y, int w_x);
int		move_grid(int ch, int **grid, int grid_size, int *win);
int		is_blocked(int **grid, int grid_size);

int		*try_left(int **grid, int y, int x, int grid_size);
int		*try_right(int **grid, int y, int x, int grid_size);
int		*try_top(int **grid, int y, int x, int grid_size);
int		*try_bottom(int **grid, int y, int x, int grid_size);
#endif
