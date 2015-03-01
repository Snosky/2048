/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:34:22 by tpayen            #+#    #+#             */
/*   Updated: 2015/03/01 13:16:17 by fvelay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

void	print_grid(int grid_size, int w_y, int w_x)
{
	int	i;

	i = 1;
	while (i < grid_size)
	{
		mvwhline(stdscr, (w_y / grid_size) * i, 1, '-', w_x - 2);
		mvwvline(stdscr, 1, (w_x / grid_size) * i, '|', w_y - 2);
		i++;
	}
}

void	show_grid(int **grid, int grid_size, int w_y, int w_x)
{
	int x;
	int y;
	int	c_y;
	int c_x;

	y = 0;
	print_grid(grid_size, w_y, w_x);
	while (y < grid_size)
	{
		x = 0;
		while (x < grid_size)
		{
			c_y = (y * 2 + 1) * (w_y / (grid_size * 2));
			c_x = (x * 2 + 1) * (w_x / (grid_size * 2));
			if (grid[y][x] == 0)
				mvprintw(c_y, c_x, " ");
			else
				mvprintw(c_y, c_x, "%d", grid[y][x]);
			x++;
		}
		printw("\n");
		y++;
	}
}
