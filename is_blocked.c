/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_blocked.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:22:36 by tpayen            #+#    #+#             */
/*   Updated: 2015/02/28 20:06:59 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

int		is_blocked(int **grid, int grid_size)
{
	int	y;
	int x;

	y = 0;
	while (y < grid_size)
	{
		x = 0;
		while (x < grid_size)
		{
			if (try_left(grid, y, x, grid_size) != 0 ||
					try_right(grid, y, x, grid_size) != 0 ||
					try_top(grid, y, x, grid_size) != 0 ||
					try_bottom(grid, y, x, grid_size) != 0)
			{
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
