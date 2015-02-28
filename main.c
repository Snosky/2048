/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:29:06 by tpayen            #+#    #+#             */
/*   Updated: 2015/02/28 17:25:35 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

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
	clear();
	noecho();
	while (ch != 32)
	{
		show_grid(grid, grid_size);
		ch = getch();
		if (ch == 65 || ch == 66 || ch == 67 || ch == 68)
		{
			move_grid(ch, grid, grid_size);
			new_number(grid, grid_size, 0);
			refresh();
		}
	}
	endwin();
	return (0);
}
