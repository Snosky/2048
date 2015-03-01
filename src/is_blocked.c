/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_blocked.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:22:36 by tpayen            #+#    #+#             */
/*   Updated: 2015/03/01 14:50:38 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

int		is_blocked(t_grid *grid)
{
	int	y;
	int x;

	y = 0;
	while (y < grid->size)
	{
		x = 0;
		while (x < grid->size)
		{
			if (try_left(grid, y, x, 0) != 0 || try_right(grid, y, x, 0) != 0 ||
					try_top(grid, y, x, 0) != 0 ||
					try_bottom(grid, y, x, 0) != 0)
			{
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
