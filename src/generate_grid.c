/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:26:40 by tpayen            #+#    #+#             */
/*   Updated: 2015/02/28 14:41:51 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

int		**generate_grid(int grid_size)
{
	int	**grid;
	int	y;

	y = grid_size;
	if (!(grid = (int **)malloc(sizeof(int *) * grid_size)))
		return (0);
	while (y)
		if (!(grid[--y] = (int *)malloc(sizeof(int) * grid_size)))
			return (0);
	new_number(grid, grid_size, 1);
	new_number(grid, grid_size, 0);
	return (grid);
}
