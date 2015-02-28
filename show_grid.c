/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:34:22 by tpayen            #+#    #+#             */
/*   Updated: 2015/02/28 17:44:13 by tpayen           ###   ########.fr       */
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
			mvprintw(y, x, "%d", grid[y][x]);
			x++;
		}
		printw("\n");
		y++;
	}
}
