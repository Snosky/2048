/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_blocked.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:22:36 by tpayen            #+#    #+#             */
/*   Updated: 2015/02/28 19:04:05 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

int		is_blocked(int **grid, int grid_size)
{
	int	y;
	int x;

	y = 0;
	x = 0;
	while (y < grid_size)
	{
		printw("1");
		while (x < grid_size)
		{
		printw("2");
			if (try_left(grid, y, x, grid_size) ||
					try_right(grid, y, x, grid_size) ||
					try_top(grid, y, x, grid_size) ||
					try_bottom(grid, y, x, grid_size))
			{
				printw("3");
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
