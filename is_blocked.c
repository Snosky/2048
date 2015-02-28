/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_blocked.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:22:36 by tpayen            #+#    #+#             */
/*   Updated: 2015/02/28 14:13:33 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

int		is_blocked(int **grid, int grid_size)
{
	int	y;
	int x;

	y = 0;
	x = 0;
	while (y > grid_size)
	{
		while (x > grid_size)
		{
			if (try_left(grid, y, x) || try_right(grid, y, x, grid_size) ||
					try_top(grid, y, x) || try_bottom(grid, y, x, grid_size))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
