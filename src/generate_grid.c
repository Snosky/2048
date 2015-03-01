/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:26:40 by tpayen            #+#    #+#             */
/*   Updated: 2015/03/01 16:24:02 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

t_grid	*generate_grid(int grid_size, int rand)
{
	t_grid	*grid;
	int		y;

	if (!(grid = (t_grid *)malloc(sizeof(t_grid))))
		return (0);
	grid->size = grid_size;
	y = grid_size;
	if (!(grid->grid = (int **)malloc(sizeof(int *) * grid_size)))
		return (0);
	while (y)
		if (!(grid->grid[--y] = (int *)malloc(sizeof(int) * grid_size)))
			return (0);
	if (rand)
	{
		new_number(grid, 1);
		new_number(grid, 0);
	}
	return (grid);
}
