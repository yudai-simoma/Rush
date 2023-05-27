/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:14:39 by yshimoma          #+#    #+#             */
/*   Updated: 2023/05/27 21:41:05 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

/*
 * マップデータの行数を取得
 * 
 * @param	ファイルディスクリプタ
 * @param	ファイル名
 * @return	行数
 */
size_t	ft_line_len(char *a_file_name) {
	ssize_t	r_size;
	size_t	r_return_num;
	char	r_buf[1];
	int		r_fd;

	r_fd = open(a_file_name, O_RDONLY);
	if (r_fd == -1)
		return (0);
	r_return_num = 1;
	while (1)
	{
		r_size = read(r_fd, r_buf, 1);
		if (r_size == -1)
		{
			close(r_fd);
			return (0);
		}
		if (r_size == 0)
		{
			close(r_fd);
			return (r_return_num);
		}
		if (r_buf[0] == '\n')
			r_return_num++;
	}
}

/*
 * マップデータを2次元配列へ格納する
 * 
 * @param	コマンドライン引数の値
 * @return	マップデータを2次元配列へ格納した値
 */
char **ft_set_dictionary(size_t	line_len) {
	int		r_fd;
	char **dictionary;
	size_t	i;

	r_fd = open(FILE_NAME, O_RDONLY);
	if (r_fd == -1)
		return NULL;
	dictionary = (char **)malloc(sizeof(char *) * (line_len + 1));
	if (dictionary == NULL)
		return NULL;
	i = 0;
	while (i < line_len)
	{
		dictionary[i] = get_next_line(r_fd);
		i++;
	}
	dictionary[i] = NULL;
	close(r_fd);
	return(dictionary);
}

int ft_init(t_wordle *wordle) {
	wordle->dictionary_size = ft_line_len(FILE_NAME);
	if (wordle->dictionary_size == 0) {
		return (0);
	}
	for (int i = 0; i < TRY_COUNT; i++) {
		for (int j = 0; j < PRINT_COUNT; j++) {
				wordle->put_str[i][j] = '_';
			wordle->color_info[i][j] = NO_COLOR_FLG;
		}
	}
	wordle->dictionary = ft_set_dictionary(wordle->dictionary_size);
	if (wordle->dictionary == NULL) {
		return (0);
	}
	srand(time(NULL));
	wordle->target_str = wordle->dictionary[rand() % (int)wordle->dictionary_size];
	return (1);
}

void ft_put_result(t_wordle *wordle) {
	for (int i = 0; i < TRY_COUNT; i++) {
		for (int j = 0; j < PRINT_COUNT; j++) {
			if (wordle->color_info[i][j] == RED_FLG)
				printf(RED_COLOR "%c " RESET_COLOR, wordle->put_str[i][j]);
			else if (wordle->color_info[i][j] == YELLOW_FLG)
				printf(YELLOW_COLOR "%c " RESET_COLOR, wordle->put_str[i][j]);
			else if (wordle->color_info[i][j] == GREY_FLG)
				printf(GREY_COLOR "%c " RESET_COLOR, wordle->put_str[i][j]);
			else
				printf("%c ", wordle->put_str[i][j]);
		}
		printf("\n");
	}
}

int ft_is_word_error(t_wordle wordle, char *input_str) {
	printf("size = %zu\n", wordle.dictionary_size);
	for (size_t i = 0; i < wordle.dictionary_size; i++) {
		if (strncmp(wordle.dictionary[i], input_str, PRINT_COUNT) == 0)
			return (0);
	}
	return (1);
}

// void ft_judgment(t_wordle *wordle, char *input_str) {
// 	for (int i = 0; i < PRINT_COUNT; i++) {
// 		for (int j = 0; j < PRINT_COUNT; j++) {
// 			if (input_str[i] == wordle->target_str[i][j]) {
// 				if (i == j)
// 					wordle->color_info[i][j];
// 			}
// 		}
// 	}
// }

//TODO:dictonaryのfree
//		判定のロジック
//		検証、リーク確認
int main(void) {
	char *input_str;
	t_wordle wordle;

	if (ft_init(&wordle) == 0)
		return (0);
	printf("str = %s", wordle.target_str);
	printf("登録されている単語は、%zu個です。\n", wordle.dictionary_size);
	ft_put_result(&wordle);
	for (int i = 0; i < TRY_COUNT; i++) {
		printf("5文字の文字を入力してください: ");
		fflush(stdout);
		input_str = get_next_line(STDIN_FILENO);
		if (strlen(input_str) > TRY_COUNT) {
			printf(RED_COLOR "文字数が多すぎます。\n" RESET_COLOR);
			i--;
			continue;
		} else if (ft_is_word_error(wordle, input_str)) {
			printf(RED_COLOR "この単語は登録されていません。\n" RESET_COLOR);
			i--;
			continue;
		} else {
			// ft_judgment(&wordle, input_str);
			ft_put_result(&wordle);
		}
	}
	return (0);
}

	// int i = 0;
	// while (wordle.dictionary[i] != NULL) {
	// 	printf("%s", wordle.dictionary[i]);
	// 	i++;
	// }
	// printf ("\ni = %d\n", i);
