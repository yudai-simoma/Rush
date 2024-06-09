/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#             */
/*   Updated: 2023/07/02 16:41:36 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

void	display(t_board *board)
{
	int	row;
	int	col;

	my_printf("\n");
	row = board->rows;
	while (row > 0)
	{
		row--;
		col = 0;
		my_printf("%d | ", row);
		while (col < board->cols)
		{
			my_printf("%c | ", g_sym_stone[board->cell[col][row]]);
			col++;
		}
		clr_right;
		col = 0;
		my_printf("\n  -");
		while (col < board->cols)
		{
			my_printf("----");
			col++;
		}
		clr_right;
		my_printf("\n");
	}
	my_printf("  ");
	col = 0;
	while (col < board->cols)
	{
		my_printf("  %c ", numFromChar(col));
		col++;
	}
	clr_right;
	my_printf("\n\n");
	clr_line();
	if (board->status == 1)
		my_printf("Player");
	else
		my_printf("AI");
	my_printf(": %s\n", board->msg);
}
