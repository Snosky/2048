/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:49:43 by tpayen            #+#    #+#             */
/*   Updated: 2015/02/28 19:20:09 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"


int		make_move(int y, int x, int **grid, int *tile)
{
	if (*tile == 0)
		*tile = grid[y][x];
	else if (*tile != 0)
		*tile = (int)grid[y][x] * 2;
	grid[y][x] = 0;
	return (1);
	
}

int		validate_move_rev(int **grid, int gs, int *(*f)(int **, int, int, int))
{
	int	move;
	int	y;
	int	x;
	int	*tile;

	y = gs - 1;
	move = 0;
	while (y >= 0)
	{
		x = gs - 1;
		while (x >= 0)
		{
			if (grid[y][x] != 0 && (tile = (*f)(grid, y, x, gs)) != 0)
				move = make_move(y, x, grid, tile);
			x--;
		}	
		y--;
	}
	return (move);
}

int		validate_move(int **grid, int gs, int *(*f)(int **, int, int, int))
{
	int	move;
	int	y;
	int	x;
	int	*tile;

	move = 0;
	y = 0;
	while (y < gs)
	{
		x = 0;
		while (x < gs)
		{
			if (grid[y][x] != 0 && (tile = (*f)(grid, y, x, gs)) != 0)
				move = make_move(y, x, grid, tile);
			x++;
		}
		y++;
	}
	return (move);
}

int		move_grid(int ch, int **grid, int grid_size)
{
	if (ch == 65)
		return (validate_move(grid, grid_size, try_top));
	else if (ch == 66)
		return (validate_move_rev(grid, grid_size, try_bottom));
	else if (ch == 67)
		return (validate_move_rev(grid, grid_size, try_right));
	else if (ch == 68)
		return (validate_move(grid, grid_size, try_left));
	return (0);
}
