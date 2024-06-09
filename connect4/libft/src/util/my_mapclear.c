/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mapclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/30 18:32:49 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_utils.h"

void	*my_mapclear(char **map, size_t size)
{
	size_t	i;

	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < size)
		free(map[i++]);
	free(map);
	map = NULL;
	return (NULL);
}
