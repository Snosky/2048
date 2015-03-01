/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:29:06 by tpayen            #+#    #+#             */
/*   Updated: 2015/03/01 13:15:46 by fvelay           ###   ########.fr       */
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
			mvprintw(10, 10, "YOU WIN");
		if (is_blocked(grid, grid_size))
			mvprintw(10, 10, "GAME OVER");
	}
	return (1);
}

int		get_grid_size(int ac, char **av)
{
	if (ac == 1)
		return (4);
	else
		return (ft_atoi(av[1]));
}

int		resize_box(int *w_y, int *w_x)
{
	int	t_y;
	int	t_x;

	if (*w_y == 0 && *w_x == 0)
		getmaxyx(stdscr, *w_y, *w_x);
	getmaxyx(stdscr, t_y, t_x);
	if (t_y != *w_y || t_x != *w_x)
	{
		getmaxyx(stdscr, *w_y, *w_x);
		return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int	**grid;
	int	grid_size;
	int ch;
	int	w_y;
	int	w_x;

	grid_size = get_grid_size(ac, av);
	grid = generate_grid(grid_size);
	initscr();
	keypad(stdscr, true);
	while (ch != 27)
	{
		if (resize_box(&w_y, &w_x))
			wclear(stdscr);
		box(stdscr, '|', '-');
		show_grid(grid, grid_size, w_y, w_x);
		ch = getch();
		if (!make_all(ch, grid, grid_size))
			break ;
		refresh();
	}
	endwin();
	return (0);
}
