/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:26:40 by tpayen            #+#    #+#             */
/*   Updated: 2015/02/28 12:37:02 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

int		**generate_grid(int grid_size)
{
	int	**grid;
	int	i;

	i = grid_size;
	if (!(grid = (int **)malloc(sizeof(int *) * grid_size)))
		return (0);
	while (i)
	{
		if (!(grid[i] = (int *)malloc(sizeof(int) * grid_size)))
			return (0);
		i--;
	}
	if (!new_number(&grid, grid_size) && !new_number(&grid, grid_size))
		return (0);
	return (grid);
}
