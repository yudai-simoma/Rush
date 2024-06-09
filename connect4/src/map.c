/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#             */
/*   Updated: 2023/07/01 22:50:19 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int	board_init(t_board *board, char **argv)
{
	int	row;
	int	col;

	board->cols = my_atoi(argv[1]);
	if (board->cols < COLS_MIN || board->cols > COLS_MAX)
		return (1);
	board->rows = my_atoi(argv[2]);
	if (board->rows < ROWS_MIN || board->rows > ROWS_MAX)
		return (1);
	board->cell = malloc(sizeof(int *) * board->cols);
	for (int i = 0; i < board->cols; i++) {
		board->cell[i] = malloc(sizeof(int) * board->rows);
	}
	row = 0;
	while (row < board->rows)
	{
		col = 0;
		while (col < board->cols)
		{
			board->cell[col][row] = 0;
			col++;
		}
		row++;
	}
	srand(time(NULL));
	board->status = rand() % 2 + 1;
	board->msg = MSG_TURN;
	return (0);
}

t_board	*put_stone(t_board *board, int col)
{
	int		row;

	if (col < 0 || col >= board->cols)
	{
		board->msg = MSG_RANGE;
		return (board);
	}
	row = 0;
	while (row < board->rows)
	{
		if (board->cell[col][row] == 0)
		{
			board->cell[col][row] = board->status;
			return (judge(board, col, row));
		}
		row++;
	}
	board->msg = MSG_FULL;
	return (board);
}

int	check_filled(t_board *board)
{
	int	col;

	col = 0;
	while (col < board->cols)
	{
		if (board->cell[col][board->rows - 1] == 0)
			return (0);
		col++;
	}
	return (1);
}

void	board_term(t_board *board)
{
    int col;
    col = 0;
    while (col < board->cols)
        free(board->cell[col++]);
    free(board->cell);
}
