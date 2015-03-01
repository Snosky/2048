/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:31:52 by tpayen            #+#    #+#             */
/*   Updated: 2015/03/01 14:00:50 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

int		*try_left(t_grid *grid, int y, int x, int only_space)
{
	int	try;
	int	*zero;

	if (x == 0 || x >= grid->size || grid->grid[y][x] == 0)
		return (0);
	try = grid->grid[y][x];
	zero = 0;
	while (x > 0)
	{
		x--;
		if (grid->grid[y][x] != 0 && grid->grid[y][x] != try)
			break ;
		else if (grid->grid[y][x] == 0)
			zero = &(grid->grid[y][x]);
		else if (!only_space && grid->grid[y][x] == try)
			return (&(grid->grid[y][x]));
	}
	return (zero);
}

int		*try_right(t_grid *grid, int y, int x, int only_space)
{
	int try;
	int *zero;

	if (x == (grid->size - 1) || grid->grid[y][x] == 0)
		return (0);
	try = grid->grid[y][x];
	zero = 0;
	while (x < (grid->size - 1))
	{
		x++;
		if (grid->grid[y][x] != 0 && grid->grid[y][x] != try)
			break ;
		else if (grid->grid[y][x] == 0)
			zero = &(grid->grid[y][x]);
		else if (!only_space && grid->grid[y][x] == try)
			return (&(grid->grid[y][x]));
	}
	return (zero);
}

int		*try_top(t_grid *grid, int y, int x, int only_space)
{
	int	try;
	int	*zero;

	if (y == 0 || y >= grid->size || grid->grid[y][x] == 0)
		return (0);
	try = grid->grid[y][x];
	zero = 0;
	while (y > 0)
	{
		y--;
		if (grid->grid[y][x] != 0 && grid->grid[y][x] != try)
			break ;
		else if (grid->grid[y][x] == 0)
			zero = &(grid->grid[y][x]);
		else if (!only_space && grid->grid[y][x] == try)
			return (&(grid->grid[y][x]));
	}
	return (zero);
}

int		*try_bottom(t_grid *grid, int y, int x, int only_space)
{
	int try;
	int *zero;

	if (y == (grid->size - 1) || grid->grid[y][x] == 0)
		return (0);
	try = grid->grid[y][x];
	zero = 0;
	while (y < (grid->size - 1))
	{
		y++;
		if (grid->grid[y][x] != 0 && grid->grid[y][x] != try)
			break ;
		else if (grid->grid[y][x] == 0)
			zero = &(grid->grid[y][x]);
		else if (!only_space && grid->grid[y][x] == try)
			return (&(grid->grid[y][x]));
	}
	return (zero);
}
