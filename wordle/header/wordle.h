/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:15:10 by yshimoma          #+#    #+#             */
/*   Updated: 2023/05/28 19:30:24 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDLE_H
# define WORDLE_H
# include <stdio.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <time.h>
# include <ctype.h>
# include "get_next_line_bonus.h"

# define RED_COLOR "\033[31m"
# define GREEN_COLOR "\033[32m"
# define YELLOW_COLOR "\033[33m"
# define GREY_COLOR "\033[90m"
# define RESET_COLOR "\033[0m"
# define FILE_NAME "./files/words.txt"
# define TRY_COUNT 6
# define PRINT_COUNT 5
# define GREEN_FLG 1
# define YELLOW_FLG 2
# define GREY_FLG 3
# define NO_COLOR_FLG 4

typedef struct s_wordle
{
	char *target_str;
	char **dictionary;
	size_t dictionary_size;
	char put_str[TRY_COUNT][PRINT_COUNT];
	int color_info[TRY_COUNT][PRINT_COUNT];
	int clear_flg;
}	t_wordle;

//utils.c
size_t	ft_line_len(char *a_file_name);
char **ft_set_dictionary(size_t	line_len);
void ft_free(t_wordle *wordle);
int ft_map_is_error(t_wordle *wordle);

#endif