/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2048.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:17:32 by tpayen            #+#    #+#             */
/*   Updated: 2015/02/28 15:10:32 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H
# include "libft/libft.h"
# include <stdlib.h>
# include <time.h>
# include <ncurses.h>

int		**generate_grid(int grid_size);
void	new_number(int **grid, int grid_size, int force_two);

int		*try_left(int **grid, int y, int x);
int		*try_top(int **grid, int y, int x);
int		*try_right(int **grid, int y, int x, int grid_size);
int		*try_bottom(int **grid, int y, int x, int grid_size);
#endif
