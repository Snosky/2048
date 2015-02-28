/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvelay <fvelay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:17:12 by fvelay            #+#    #+#             */
/*   Updated: 2015/02/28 12:56:23 by fvelay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include "2048.h"

void	get_new_number(int **grid)
{
	int	i;
	int	j;
	unsigned int	target;
	unsigned int	empty_tiles;

	empty_tiles = get_empty_tiles(*grid);
	target = rand() % empty_tiles;
}
