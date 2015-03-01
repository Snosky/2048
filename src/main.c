/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:29:06 by tpayen            #+#    #+#             */
/*   Updated: 2015/03/01 17:42:11 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

static int	make_all(int ch, t_grid *grid, int *win)
{
	if (ch == 258 || ch == 259 || ch == 260 || ch == 261)
	{
		if (move_grid(ch, grid, win))
			new_number(grid, 0);
		wclear(stdscr);
		if (*win == 1)
			mvprintw(10, 10, "YOU WIN");
		if (is_blocked(grid))
			mvprintw(10, 10, "GAME OVER");
	}
	return (1);
}

static int	get_grid_size(int ac, char **av)
{
	if (ac == 1)
		return (4);
	else
		return (ft_atoi(av[1]));
}

static int	resize_box(int *w_y, int *w_x)
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

static void	bad_win_value(void)
{
	if (WIN_VALUE == 1 || (WIN_VALUE & (WIN_VALUE - 1)))
	{
		ft_putstr("Please change your win value");
		exit(1);
	}
}

int			main(int ac, char **av)
{
	t_grid	*grid;
	int		ch;
	int		win;
	int		w_y;
	int		w_x;

	ch = 0;
	win = 0;
	grid = generate_grid(get_grid_size(ac, av), 1);
	bad_win_value();
	initscr();
	noecho();
	keypad(stdscr, true);
	while (ch != 27)
	{
		if (resize_box(&w_y, &w_x))
			wclear(stdscr);
		show_grid(grid, w_y, w_x);
		ch = getch();
		if (!make_all(ch, grid, &win))
			break ;
		refresh();
	}
	endwin();
	return (0);
}
