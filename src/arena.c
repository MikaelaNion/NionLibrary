/**
 * Nion Library - Memory Arena
 * Mikaela Nion
 * @built: 2025-09-25
 * @version: 0.0.0.0.20250925
 * @license: MIT
 */

#include <stdlib.h>
#include "../include/arena.h"

Arena *arena_create(size_t size) {
    Arena *arena = (Arena *)malloc(sizeof(Arena));
    if (NULL == arena) {
        return NULL;
    }

    arena->buffer = (char *)malloc(size);
    if (NULL == arena->buffer) {
        free(arena);
        return NULL;
    }

    arena->size = size;
    arena->offset = 0;
    return arena;
}

void *arena_alloc(Arena *arena, size_t size) {
    if (arena->offset + size > arena->size) {
        return NULL;
    }
    
    void *ptr = arena->buffer + arena->offset;
    arena->offset += size;
    return ptr;
}

void arena_reset(Arena *arena) {
    arena->offset = 0;
}

void arena_destroy(Arena *arena) {
    if (arena) {
        free(arena->buffer);
        free(arena);
    }
}