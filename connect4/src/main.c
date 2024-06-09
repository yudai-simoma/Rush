/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#             */
/*   Updated: 2023/07/02 20:13:08 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

const unsigned char	g_sym_stone[] = {' ', 'o', 'x'};

int	err_msg()
{
	my_printf("Invalid arguments\n");
	return (1);
}

int	main(int argc, char **argv)
{
	t_board	board;
	int		input;

	if (argc != 3 || board_init(&board, argv))
		return (err_msg());
	while (board.status > 0)
	{
		display(&board);
		if (board.status % 2)
			input = control(&board);
		else
			input = computer(&board);
		put_stone(&board, input);
		my_printf("\n\n\n");
	}
	board.status = -board.status;
	display(&board);
	board_term(&board);
	return (0);
}
