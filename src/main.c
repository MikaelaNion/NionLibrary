
#include <stdio.h>
#include "nionlib.h"

void main(void) {
    // Example usage of the arena allocator
    Arena *arena = arena_create(1024); // Create an arena with 1KB
    if (arena) {
        int *arr = (int *)arena_alloc(arena, 10 * sizeof(int)); // Allocate space for 10 integers
        if (arr) {
            for (int i = 0; i < 10; i++) {
                arr[i] = i * i; // Initialize array
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
        arena_reset(arena); // Reset the arena for reuse
        arena_destroy(arena); // Clean up
    }
    return;
}