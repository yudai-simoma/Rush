/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#             */
/*   Updated: 2023/07/02 17:17:00 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int	judge_horizon(t_board *board, int row)
{
	int	x;
	int	connected;

	x = 0;
	connected = 0;
	while (x < board->cols && connected < TO_CONNECT)
	{
		if (board->cell[x][row] == board->status)
			connected++;
		else
			connected = 0;
		x++;
	}
	if (connected < TO_CONNECT)
		return (0);
	return (connected);
}

int	judge_vertic(t_board *board, int col)
{
	int	y;
	int	connected;

	y = 0;
	connected = 0;
	while (y < board->rows && connected < TO_CONNECT)
	{
		if (board->cell[col][y] == board->status)
			connected++;
		else
			connected = 0;
		y++;
	}
	if (connected < TO_CONNECT)
		return (0);
	return (connected);
}

int	judge_ascend(t_board *board, int col, int row)
{
	int	x;
	int	y;
	int	connected;

	x = 0;
	y = 0;
	if (col > row)
		x = col - row;
	else
		y = row - col;
	connected = 0;
	while (x < board->cols && y < board->rows && connected < TO_CONNECT)
	{
		if (board->cell[x][y] == board->status)
			connected++;
		else
			connected = 0;
		x++;
		y++;
	}
	if (connected < TO_CONNECT)
		return (0);
	return (connected);
}

int	judge_descend(t_board *board, int col, int row)
{
	int	x;
	int	y;
	int	connected;

	x = 0;
	y = board->rows - 1;
	if (col + row > board->rows - 1)
		x = col + row - board->rows + 1;
	else
		y = row + col;
	connected = 0;
	while (x < board->cols && y >= 0 && connected < TO_CONNECT)
	{
		if (board->cell[x][y] == board->status)
			connected++;
		else
			connected = 0;
		x++;
		y--;
	}
	if (connected < TO_CONNECT)
		return (0);
	return (connected);
}

t_board	*judge(t_board *board, int col, int row)
{
	int	match;

	match = judge_horizon(board, row);
	match += judge_vertic(board, col);
	match += judge_ascend(board, col, row);
	match += judge_descend(board, col, row);
	if (match > 0)
	{
		board->msg = MSG_WIN;
		board->status = -board->status;
	}
	else
	{
		if(check_filled(board))
		{
			board->msg = MSG_DRAW;
			board->status = 0;
		}
		else
		{
			board->msg = MSG_TURN;
			board->status = board->status % 2 + 1;
		}
	}
	return (board);
}
