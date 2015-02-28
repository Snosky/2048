/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:29:06 by tpayen            #+#    #+#             */
/*   Updated: 2015/02/28 20:40:15 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

int		make_all(int ch, int **grid, int grid_size)
{
	int	win;

	win = 0;
	if (ch == 258 || ch == 259 || ch == 260 || ch == 261)
	{
		if (move_grid(ch, grid, grid_size, &win))
			new_number(grid, grid_size, 0);
		wclear(stdscr);
		if (win)
			mvprintw(10, 0, "GG");
		if (is_blocked(grid, grid_size))
			mvprintw(10, 0, "GAME OVER");
	}
	return (1);
}

int		main(int ac, char **av)
{
	int	**grid;
	int	grid_size;
	int ch;

	grid_size = 4;
	if (ac == 2)
		grid_size = ft_atoi(av[1]);
	grid = generate_grid(grid_size);
	initscr();
	keypad(stdscr, true);
	while (ch != 27)
	{
		show_grid(grid, grid_size);
		ch = getch();
		if (!make_all(ch, grid, grid_size))
			break;
		refresh();
	}
	endwin();
	return (0);
}
