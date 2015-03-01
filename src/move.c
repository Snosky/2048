/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:49:43 by tpayen            #+#    #+#             */
/*   Updated: 2015/03/01 17:41:38 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

static int	make_calc(int *grid, int *tile)
{
	if (*tile != 0)
	{
		*grid *= 2;
		*tile = 0;
	}
	if (*grid == WIN_VALUE)
		return (1);
	return (0);
}

static int	make_move(int y, int x, int **grid, int *tile)
{
	if (*tile == 0)
	{
		*tile = grid[y][x];
		grid[y][x] = 0;
		return (1);
	}
	return (0);
}

static int	v_move_r(t_grid *grid, int *(*f)(t_grid *, int, int, int), int *win)
{
	int	move;
	int	y;
	int	x;
	int	*tile;

	y = grid->size;
	move = 0;
	while (--y >= 0)
	{
		x = grid->size;
		while (--x >= 0)
			if (grid->grid[y][x] && (tile = (*f)(grid, y, x, 0)) && *tile != 0)
				*win += make_calc(&(grid->grid[y][x]), tile);
		x = grid->size;
		while (--x >= 0)
			if (grid->grid[y][x] && (tile = (*f)(grid, y, x, 1)) && *tile == 0)
				move = make_move(y, x, grid->grid, tile);
	}
	return (move);
}

static int	v_move(t_grid *grid, int *(*f)(t_grid *, int, int, int), int *win)
{
	int	y;
	int	x;
	int	*tile;
	int	move;

	y = -1;
	move = 0;
	while (++y < grid->size)
	{
		x = -1;
		while (++x < grid->size)
			if (grid->grid[y][x] && (tile = (*f)(grid, y, x, 0)) && *tile != 0)
				*win += make_calc(&(grid->grid[y][x]), tile);
		x = -1;
		while (++x < grid->size)
			if (grid->grid[y][x] && (tile = (*f)(grid, y, x, 1)) && *tile == 0)
				move = make_move(y, x, grid->grid, tile);
	}
	return (move);
}

int			move_grid(int ch, t_grid *grid, int *win)
{
	if (ch == 259)
		return (v_move(grid, try_top, win));
	else if (ch == 258)
		return (v_move_r(grid, try_bottom, win));
	else if (ch == 261)
		return (v_move_r(grid, try_right, win));
	else if (ch == 260)
		return (v_move(grid, try_left, win));
	return (0);
}
