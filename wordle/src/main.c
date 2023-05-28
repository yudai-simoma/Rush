/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:14:39 by yshimoma          #+#    #+#             */
/*   Updated: 2023/05/28 19:27:04 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

/*
 * 構造体の初期化
 *   ・辞書ファイルの行数を取得
 *   ・辞書ファイルを文字列へ格納
 *   ・ターミナルへ出力する文字情報を格納
 */
int ft_init(t_wordle *wordle) {
	wordle->dictionary_size = ft_line_len(FILE_NAME);
	if (wordle->dictionary_size == 0) {
		return (0);
	}
	if (ft_map_is_error(wordle)) {
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
	wordle->clear_flg = 0;
	return (1);
}

/*
 * ターミナルにマスの情報を表示する
 */
void ft_put_result(t_wordle *wordle) {
	for (int i = 0; i < TRY_COUNT; i++) {
		for (int j = 0; j < PRINT_COUNT; j++) {
			if (wordle->color_info[i][j] == GREEN_FLG)
				printf(GREEN_COLOR "%c " RESET_COLOR, wordle->put_str[i][j]);
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

/*
 * 入力された文字が辞書の中にあるか判断する
 */
int ft_is_word_error(t_wordle wordle, char *input_str) {
	for (size_t i = 0; i < wordle.dictionary_size; i++) {
		if (strncmp(wordle.dictionary[i], input_str, PRINT_COUNT) == 0)
			return (0);
	}
	return (1);
}

/*
 * 入力文字とターゲットが一致しているか判断する。フラグを設定する。
 */
void ft_judgment(t_wordle *wordle, char *input_str, int index) {
	int jud_flg[5];

	bzero(jud_flg, sizeof(int) * 5);
	for (int i = 0; i < PRINT_COUNT; i++) {
		wordle->put_str[index][i] = toupper(input_str[i]);
		wordle->color_info[index][i] = GREY_FLG;
		for (int j = 0; j < PRINT_COUNT; j++) {
			if (toupper(input_str[i]) == toupper(wordle->target_str[j])) {
				if (i == j) {
					wordle->color_info[index][i] = GREEN_FLG;
					jud_flg[i] = 1;
				}
			}
		}
	}
	for (int i = 0; i < PRINT_COUNT; i++) {
		wordle->put_str[index][i] = toupper(input_str[i]);
		for (int j = 0; j < PRINT_COUNT; j++) {
			if (jud_flg[j] == 0 && toupper(input_str[i]) == toupper(wordle->target_str[j])) {
				if (wordle->color_info[index][i] != GREEN_FLG) {
					wordle->color_info[index][i] = YELLOW_FLG;
					jud_flg[j] = 1;
					break;
				}
			}
		}
	}
}

/*
 * 入力文字が全てあっているか判断する関数
 * 全て緑なら1を返す
 */
int ft_is_finish(t_wordle wordle, int index) {
	for (int i = 0; i < PRINT_COUNT; i++) {
		if (wordle.color_info[index][i] != GREEN_FLG) {
			return (0);
		}
	}
	return (1);
}

int main(void) {
	char *input_str;
	t_wordle wordle;

	if (ft_init(&wordle) == 0)
		return (0);
	printf("登録されている単語は、%zu個です。\n", wordle.dictionary_size);
	ft_put_result(&wordle);
	for (int i = 0; i < TRY_COUNT; i++) {
		printf("5文字の文字を入力してください: ");
		fflush(stdout);
		input_str = get_next_line(STDIN_FILENO);
		if (strlen(input_str) > TRY_COUNT) {
			printf(RED_COLOR "文字数が多いです。\n" RESET_COLOR);
			free(input_str);
			i--;
			continue;
		} else if (strlen(input_str) < TRY_COUNT) {
			printf(RED_COLOR "文字数が少ないです。\n" RESET_COLOR);
			free(input_str);
			i--;
			continue;
		} else if (ft_is_word_error(wordle, input_str)) {
			printf(RED_COLOR "この単語は登録されていません。\n" RESET_COLOR);
			free(input_str);
			i--;
			continue;
		} else {
			ft_judgment(&wordle, input_str, i);
			ft_put_result(&wordle);
			free(input_str);
			if (ft_is_finish(wordle, i)) {
				printf("クリア！\n");
				wordle.clear_flg = 1;
				fflush(stdout);
				break;
			}
		}
	}
	if (wordle.clear_flg == 0) {
		printf("答えは%s", wordle.target_str);
	}
	ft_free(&wordle);
	return (0);
}

// #include <libc.h>

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q wordle");
// }
