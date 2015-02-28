/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:49:43 by tpayen            #+#    #+#             */
/*   Updated: 2015/02/28 17:35:00 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

void	validate_move(int **grid, int gs, int *(*f)(int **, int, int, int))
{
	int	x;
	int	y;
	int	*tile;

	y = 0;
	while (y < gs)
	{
		x = 0;
		while (x < gs)
		{
			if (grid[y][x] != 0 && (tile = (*f)(grid, y, x, gs)))
			{
				if (*tile == 0)
					*tile = grid[y][x];
				else
					*tile *= 2;
				grid[y][x] = 0;
			}
			x++;
		}
		y++;
	}
}

void	move_grid(int ch, int **grid, int grid_size)
{
	if (ch == 65)
	{
		printw("Move top");
		validate_move(grid, grid_size, try_top);
	}
	else if (ch == 66)
	{
		printw("Move bottom");
		validate_move(grid, grid_size, try_bottom);
	}
	else if (ch == 67)
	{
		printw("Move right");
		validate_move(grid, grid_size, try_right);
	}
	else if (ch == 68)
	{
		printw("Move left");
		validate_move(grid, grid_size, try_left);
	}
}
