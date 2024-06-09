/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#             */
/*   Updated: 2023/07/02 17:29:42 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"
//col=何列目、row=何行目
//縦
int	check_chain_vertic(t_board *board, int col, int row)
{
	int	connected;

	connected = 1;
	while (row-- > 0)
	{
		if (board->cell[col][row] == board->status)
			connected++;
		else
			return (connected);
	}
	return (connected);
}
//横
int	check_chain_horizon(t_board *board, int col, int row)
{
	int	connected;
	int	x;

	connected = 1;
	x = col;
	while (++x < board->cols)
	{
		if (board->cell[x][row] == board->status)
			connected++;
		else
			break;
	}
	x = col;
	while (x-- > 0)
	{
		if (board->cell[x][row] == board->status)
			connected++;
		else
			return (connected);
	}
	return (connected);
}
// "/"
int	check_chain_ascend(t_board *board, int col, int row)
{
	int	connected;
	int	x;
	int	y;

	connected = 1;
	x = col;
	y = row;
	while (++x < board->cols && ++y < board->rows)
	{
		if (board->cell[x][y] == board->status)
			connected++;
		else
			break;
	}
	x = col;
	y = row;
	while (x-- > 0 && y-- > 0)
	{
		if (board->cell[x][y] == board->status)
			connected++;
		else
			return (connected);
	}
	return (connected);
}
// "\"
int	check_chain_descend(t_board *board, int col, int row)
{
	int	connected;
	int	x;
	int	y;

	connected = 1;
	x = col;
	y = row;
	while (x-- > 0 && ++y < board->rows)
	{
		if (board->cell[x][y] == board->status)
			connected++;
		else
			break;
	}
	x = col;
	y = row;
	while (++x < board->cols && y-- > 0)
	{
		if (board->cell[x][y] == board->status)
			connected++;
		else
			return (connected);
	}
	return (connected);
}

int	check_chain(t_board *board, int col)
{
	int	max_chain;
	int	cur_chain;
	int	row;

	row = 0;
	max_chain = 0;
	while (row < board->rows)
	{
		if (board->cell[col][row] == 0)
		{
			cur_chain = check_chain_vertic(board, col, row);
			max_chain = (cur_chain > max_chain ? cur_chain : max_chain);
			cur_chain = check_chain_horizon(board, col, row);
			max_chain = (cur_chain > max_chain ? cur_chain : max_chain);
			cur_chain = check_chain_ascend(board, col, row);
			max_chain = (cur_chain > max_chain ? cur_chain : max_chain);
			cur_chain = check_chain_descend(board, col, row);
			max_chain = (cur_chain > max_chain ? cur_chain : max_chain);
			return (max_chain);
		}
		row++;
	}
	return (0);
}
