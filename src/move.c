/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:49:43 by tpayen            #+#    #+#             */
/*   Updated: 2015/02/28 20:41:40 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

int		make_move(int y, int x, int **grid, int *tile)
{
	int	win;

	win = 0;
	if (*tile == 0)
		*tile = grid[y][x];
	else if (*tile != 0)
		*tile = (int)grid[y][x] * 2;
	if (*tile == WIN_VALUE)
		win = 1;
	grid[y][x] = 0;
	return (win);
}

int		v_move_r(int **grid, int gs, int *(*f)(int **, int, int, int), int *win)
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
			{
				move = 1;
				*win = make_move(y, x, grid, tile);
			}
			x--;
		}
		y--;
	}
	return (move);
}

int		v_move(int **grid, int gs, int *(*f)(int **, int, int, int), int *win)
{
	int	y;
	int	x;
	int	*tile;
	int	move;

	y = 0;
	move = 0;
	while (y < gs)
	{
		x = 0;
		while (x < gs)
		{
			if (grid[y][x] != 0 && (tile = (*f)(grid, y, x, gs)) != 0)
			{
				move = 1;
				*win = make_move(y, x, grid, tile);
			}
			x++;
		}
		y++;
	}
	return (move);
}

int		move_grid(int ch, int **grid, int grid_size, int *win)
{
	if (ch == 259)
		return (v_move(grid, grid_size, try_top, win));
	else if (ch == 258)
		return (v_move_r(grid, grid_size, try_bottom, win));
	else if (ch == 261)
		return (v_move_r(grid, grid_size, try_right, win));
	else if (ch == 260)
		return (v_move(grid, grid_size, try_left, win));
	return (0);
}
