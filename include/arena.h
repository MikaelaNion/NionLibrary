/**
 * Nion Library
 * Mikaela Nion
 * @built: 2025-09-25
 * @version: 0.0.0.0.20250925
 * @license: MIT
 */

#ifndef NIONLIB_ARENA_H
#define NIONLIB_ARENA_H

#include <stddef.h>

typedef struct {
    char *buffer; // Start of allocated block
    size_t size;  // Total size in bytes
    size_t offset; // Current position
} Arena;

Arena* arena_create(size_t size);
void* arena_alloc(Arena *arena, size_t size);
void arena_reset(Arena *arena);
void arena_destroy(Arena *arena);

#endif // NIONLIB_ARENA_H