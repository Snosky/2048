/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:31:52 by tpayen            #+#    #+#             */
/*   Updated: 2015/02/28 17:38:26 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

int		*try_left(int **grid, int y, int x, int grid_size)
{
	int	try;
	int	*zero;

	(void)grid_size;
	if (x == 0 || grid[y][x] == 0)
		return (0);
	try = grid[y][x];
	while (x >= 0)
	{
		x--;
		if (grid[y][x] != try && grid[y][x] != 0)
			break ;
		else if (grid[y][x] == try)
			return (&(grid[y][x]));
		else if (grid[y][x] == 0)
			zero = &(grid[y][x]);
	}
	return (zero);
}

int		*try_right(int **grid, int y, int x, int grid_size)
{
	int	try;
	int	*zero;

	if (x == grid_size - 1 || grid[y][x] == 0)
		return (0);
	try = grid[y][x];
	while (x < grid_size)
	{
		x++;
		if (grid[y][x] != try && grid[y][x] != 0)
			break ;
		else if (grid[y][x] == try)
			return (&(grid[y][x]));
		else if (grid[y][x] == 0)
			zero = &(grid[y][x]);
	}
	return (zero);
}

int		*try_top(int **grid, int y, int x, int grid_size)
{
	int	try;
	int	*zero;

	(void)grid_size;
	if (y == 0 || grid[y][x] == 0)
		return (0);
	try = grid[y][x];
	while (y >= 0)
	{
		y--;
		if (grid[y][x] != try && grid[y][x] != 0)
			break ;
		else if (grid[y][x] == try)
			return (&(grid[y][x]));
		else if (grid[y][x] == 0)
			zero = &(grid[y][x]);
	}
	return (zero);
}

int		*try_bottom(int **grid, int y, int x, int grid_size)
{
	int	try;
	int	*zero;

	if (y == grid_size - 1 || grid[y][x] == 0)
		return (0);
	try = grid[y][x];
	while (y < grid_size)
	{
		y++;
		if (grid[y][x] != try && grid[y][x] != 0)
			break ;
		else if (grid[y][x] == try)
			return (&(grid[y][x]));
		else if (grid[y][x] == 0)
			zero = &(grid[y][x]);
	}
	return (zero);
}
