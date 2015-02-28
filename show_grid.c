/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:34:22 by tpayen            #+#    #+#             */
/*   Updated: 2015/02/28 18:24:52 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

void	show_grid(int **grid, int grid_size)
{
	int x;
	int y;

	y = 0;
	while (y < grid_size)
	{
		x = 0;
		while (x < grid_size)
		{
			if (grid[y][x] == 0)
				mvprintw(y * 3, x * 3, ".");
			else
				mvprintw(y * 3, x * 3, "%d", grid[y][x]);
			x++;
		}
		printw("\n");
		y++;
	}
}
