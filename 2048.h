/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2048.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:17:32 by tpayen            #+#    #+#             */
/*   Updated: 2015/02/28 13:04:50 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 2048_H
# define 2048_H
int		**generate_grid(int grid_size);
int		new_number(int **grid, int grid_size);

int		*try_left(int **grid, int y, int x);
int		*try_top(int **grid, int y, int x);
int		*try_right(int **grid, int y, int x, int grid_size);
int		*try_bottom(int **grid, int y, int x, int grid_size);
#endif
