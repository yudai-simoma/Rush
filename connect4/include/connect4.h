/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect4.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#             */
/*   Updated: 2023/07/02 17:30:48 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONNECT4_H
# define CONNECT4_H

# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <limits.h>
# include "libft.h"

# define TO_CONNECT	4
# define COLS_MIN	7
# define COLS_MAX	36
# define ROWS_MIN	6
# define ROWS_MAX	40
# define MSG_TURN	"Your turn (Input the column ID you want to put.)"
# define MSG_RANGE	"Unable to put (the column is out of range.)"
# define MSG_FULL	"Unable to put (the column is full filled.)"
# define MSG_WIN	"WIN!"
# define MSG_DRAW	"DRAW GAME!"

# define clr		my_printf("\033[2J") // Clear terminal
# define clr_right	my_printf("\033[0K") // Clear from the cursor to end of line
# define clr_left	my_printf("\033[1K") // Clear from the cursor to head of line
# define clr_line()	my_printf("\033[2K") // Clear the line
# define location(x,y)	my_printf("\033[%d;%dH" ,x,y) // Move the cursor to
# define right(x)	my_printf("\033[%dC" ,x) // Move the cursor right
# define left(x)	my_printf("\033[%dD" ,x) // Move the cursor left
# define down(y)	my_printf("\033[%dB" ,y) // Move the cursor down
# define up(y)		my_printf("\033[%dA" ,y) // Move the cursor up

typedef struct s_board
{
	int		**cell;
	int		status;
	char	*msg;
	int		cols;
	int		rows;
}	t_board;

extern const unsigned char	g_sym_stone[];
int		board_init(t_board *board, char **argv);
void	board_term(t_board *board);
t_board	*put_stone(t_board *board, int col);
int		check_filled(t_board *board);
t_board	*judge(t_board *board, int col, int row);
void	display(t_board *board);
int		control(t_board *board);
int		computer(t_board *board);
int		check_chain(t_board *board, int col);

//utils.c
char	numFromChar(int n);

#endif
