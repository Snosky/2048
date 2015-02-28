/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:41:37 by tpayen            #+#    #+#             */
/*   Updated: 2015/02/28 14:42:39 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

int		*get_free_tile(int **grid, int grid_size)
{
	int	x_rand;
	int	y_rand;
	int	stop;
	
	stop = 1;
	srand(time(NULL));
	while (stop)
	{
		stop = 0;
		x_rand = rand() % grid_size;
		y_rand = rand() % grid_size;
		if (grid[y_rand][x_rand] != 0)
			stop = 1;
	}
	return (&(grid[y_rand][x_rand]));
}

void	new_number(int **grid, int grid_size, int force_two)
{
	int	*free_tile;

	free_tile = get_free_tile(grid, grid_size);
	srand(time(NULL));
	if (force_two)
		*free_tile = 2;
	else
		*free_tile = ((rand() % 10) < 9) ? 2 : 4;
}
