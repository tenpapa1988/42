#include <unistd.h>
#include <stdlib.h>

#define SIZE 4

// 解の書き出し時に使用
int write_number(int num) {
	if (num < 10) {
		char c = '0' + num;
		write(1, &c, 1);
	}
	return 0;
}

int is_valid(int board[SIZE][SIZE], int row, int col, int number, int clues[16]) {
	int i = 0;
    
    // 今注目している(col, row)の同列・同行にnumberがすでに存在したらFALSE
	while (i < SIZE) {
		if (board[row][i] == number || board[i][col] == number) {
			return 0;
		}
		i++;
	}

    // なぜnumberを使わず判定できる？
	// なぜ右端の列だけ？
	if (col == SIZE - 1) {
        // 列方向について極大値の更新をして、見えるビルの数を数え上げ
        // なぜ片方向からだけ？
		int visible_boxes = 0, max_height = 0, j = 0;
		while (j < SIZE) {
			if (board[row][j] > max_height) {
				max_height = board[row][j];
				visible_boxes++;
			}
			j++;
		}
        // 見えるビルの数が、対応する入力値と異なったらFALSE
		if (visible_boxes != clues[4 + row] && clues[4 + row] != 0) return 0;
	}

    // なぜ一番下の行だけ？
	if (row == SIZE - 1) {
        // 行方向について極大値の更新をして、見えるビルの数を数え上げ
        // なぜ片方向からだけ？
		int visible_boxes = 0, max_height = 0, j = 0;
		while (j < SIZE) {
			if (board[j][col] > max_height) {
				max_height = board[j][col];
				visible_boxes++;
			}
			j++;
		}
        // 見えるビルの数が、対応する入力値と異なったらFALSE
		if (visible_boxes != clues[12 + col] && clues[12 + col] != 0) return 0;
	}

	return 1;
}

// 1つのマス目(pos)に注目して解く
int solve_skyscrapers(int board[SIZE][SIZE], int clues[16], int pos) {
    // 全部のマス目を走査し切ったら完了
	if (pos == SIZE * SIZE) {
		return 1;
	}

	// マス目番号から座標(col, row)に変換
	int row = pos / SIZE;
	int col = pos % SIZE;
    // ビルの高さ
	int number = 1;

	while (number <= SIZE) {
		if (is_valid(board, row, col, number, clues)) {
            // (col, row)のビルの高さをnumberで確定
			board[row][col] = number;
            // 次のマス目(pos)についての検証
			if (solve_skyscrapers(board, clues, pos + 1)) {
                // 走査し切って答えが出たら、TRUEをmainに返す
				return 1;
			}
			board[row][col] = 0;
		}
		number++;
	}
    // 正しい答えが存在しなかったらFALSE
	return 0;
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		char usage[] = "Usage: ./rush-01 \"clues\"\n";
		write(1, usage, sizeof(usage) - 1);
		return 1;
	}

	// 入力値をcluesに格納
	int *clues = (int *)malloc(16 * sizeof(int));
	char *input_str = argv[1];
	int i = 0, j = 0;

	while (i < 16) {
		if (*input_str >= '1' && *input_str <= '4') {
			clues[i] = *input_str - '0';
			i++;
		}
		input_str++;
	}

	// board(答え)を用意し、0で初期化
	int (*board)[SIZE] = (int (*)[SIZE])malloc(SIZE * SIZE * sizeof(int));
	i = 0;
	while (i < SIZE) {
		j = 0;
		while (j < SIZE) {
			board[i][j] = 0;
			j++;
		}
		i++;
	}

	if (solve_skyscrapers(board, clues, 0)) {
        // 解が存在したら答えの書き出し
		i = 0;
		while (i < SIZE) {
			j = 0;
			while (j < SIZE) {
				write_number(board[i][j]);
				if (j < SIZE - 1) write(1, " ", 1);
				j++;
			}
			write(1, "\n", 1);
			i++;
		}
	} else {
    	// 解が存在しなかったらエラーメッセージ
		char no_solution[] = "No solution found.\n";
		write(1, no_solution, sizeof(no_solution) - 1);
	}

	// メモリ解放
	free(board);
	free(clues);
	return 0;
}
