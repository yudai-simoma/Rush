/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#             */
/*   Updated: 2023/07/02 16:03:36 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

static int	check_row(t_board *board, int row)
{
	int	col;

	col = 0;
	while (col < board->cols)
	{
		if (board->cell[col][row] != 0)
			return (board->cell[col][row]);
		col++;
	}
	return (0);
}

int	computer(t_board *board)
{
	int	col;
	int	max_chain;
	int	max_col;
	int	cur_chain;

	if (check_row(board, 0) == 0)
		return (board->cols / 2);
	col = 0;
	max_chain = 1;
	max_col = -1;
	while (col < board->cols)
	{
		cur_chain = check_chain(board, col);
		if (cur_chain > max_chain)
		{
			max_col = col;
			max_chain = cur_chain;
		}
		col++;
	}
	if (max_col >= 0)
		return (max_col);
	srand(time(NULL));
	return (rand() % board->cols);
}
