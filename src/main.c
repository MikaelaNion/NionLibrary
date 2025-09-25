
#include <stdio.h>
#include "../include/nionlib.h"

int main(void) {
    // Create an arena with 1KB
    Arena *arena = arena_create(1024);
    printf("sizeof(arena): %ld\n", sizeof(arena));
    if (arena) {
        int *arr = (int *)arena_alloc(arena, 10 * sizeof(int));
        if (arr) {
            for (int i = 0; i < 10; i++) {
                arr[i] = i * i;
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
        printf("sizeof(arr): %ld\n", sizeof(arr));
        printf("sizeof(arena): %ld\n", sizeof(arena));
        arena_reset(arena);
        arena_destroy(arena);
    }
    return 0;
}