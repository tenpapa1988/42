#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

// メモリ割り当てを行い、割り当てに失敗した場合はエラーメッセージを表示する関数
void *safeMalloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

// メモリ解放を安全に行う関数
void safeFree(void *ptr) {
    if (ptr != NULL) {
        free(ptr);
    }
}
