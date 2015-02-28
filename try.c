/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:31:52 by tpayen            #+#    #+#             */
/*   Updated: 2015/02/28 13:03:28 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

int		*try_left(int **grid, int y, int x)
{
	int	try;

	if (x == 0 || grid[y][x] == 0)/* Si la casse est vide */
		return (0);
	try = grid[y][x];
	while (x >= 0)
	{
		x--;
		if (grid[y][x] == try)
			return (&(grid[y][x]));
	}
	return (0);
}

int		*try_right(int **grid, int y, int x, int grid_size)
{
	int	try;

	if (x == grid_size - 1 || grid[y][x] == 0)
		return (0);
	try = grid[y][x];
	while (x <= grid_size - 1)
	{
		x++;
		if (grid[y][x] == try)
			return (&(grid[y][x]));
	}
	return (0);
}

int		*try_top(int **grid, int y, int x)
{
	int	try;

	if (y == 0 || grid[y][x] == 0)
		return (0);
	try = grid[y][x];
	while (y >= 0)
	{
		y--;
		if (grid[y][x] == try)
			return (&(grid[y][x]));
	}
	return (0);
}

int		*try_bottom(int **grid, int y, int x, int grid_size)
{
	int	try;

	if (x == grid_size - 1 || grid[y][x] == 0)
		return (0);
	try = grid[y][x];
	while (y <= grid_size - 1)
	{
		y--;
		if (grid[y][x] == try)
			return (&(grid[y][x]));
	}
	return (0);
}
