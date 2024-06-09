/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#             */
/*   Updated: 2023/07/02 17:29:53 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int	control(t_board *board)
{
	char	hit;
	char	buf[10000];
	int		i;

	read(0, buf, 10000);
	hit = my_tolower(buf[0]);
	i = 0;
	while (i < board->cols)
	{
		if (hit == numFromChar(i))
			return (i);
		i++;
	}
	return (-1);
}
