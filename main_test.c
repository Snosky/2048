/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 14:02:46 by tpayen            #+#    #+#             */
/*   Updated: 2015/02/28 15:19:58 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

int	main(int ac, char **av)
{
	int grid_size;
	int	**grid;
	int	x;
	int	y;
	int ch;

	y = 0;
	if (ac == 2)
		grid_size = ft_atoi(av[1]);
	else
		grid_size = 4;
	grid = generate_grid(grid_size);

	initscr();
	clear();
	noecho();
	while (ch != 27)
	{
		while (y < grid_size)
		{
			x = 0;
			while (x < grid_size)
			{
				mvprintw(y, x, "%d", grid[y][x]);
				x++;
			}
			mvprintw(y + 1, x + 1, "\n");
			y++;
		}
		ch = getch();
		if (ch == KEY_LEFT)
			printw("YO");
		refresh();
	}
	endwin();
	return (0);
}
