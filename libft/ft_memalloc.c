/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 17:34:44 by tpayen            #+#    #+#             */
/*   Updated: 2015/01/15 17:31:59 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*ret;

	if (!(ret = (char *)malloc(size)))
		return (NULL);
	while (size--)
	{
		*ret = 0;
		ret++;
	}
	return (ret);
}
