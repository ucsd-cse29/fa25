#include "malloc.h"
#include <sys/mman.h>
#include <stdio.h>
#include <stdint.h>

uint64_t* HEAP_START = NULL;
#define HEAP_SIZE_BYTES 240
#define HEAP_WORDS HEAP_SIZE_BYTES/8

void init_heap() {
  HEAP_START = mmap(NULL, HEAP_SIZE_BYTES, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  HEAP_START[0] = HEAP_SIZE_BYTES;
}

void print_heap() {
  int i = 0;
  uint64_t* start = HEAP_START;
  while(i < HEAP_WORDS) {
    uint64_t h = start[i];
    if(h % 2 == 0)
      printf("%p : %llu [%llu bytes FREE]\n", &start[i], h, h);
    else
      printf("%p : %llu [%llu bytes BUSY]\n", &start[i], h, h - 1);
    i += h / 8;
  } 
}

// Returns a pointer to the header of a block of at least size bytes
uint64_t* find_block(uint64_t* start, size_t size);

/* Splits the block into two, one busy, one free.
   Note also that the current block size and size are 8-byte aligned */
void split_block(uint64_t* block_start, size_t size);

/* Returns the size of a block for a given malloc request:
   rounded up to nearest 8, plus 8 for header */
size_t block_size_of(size_t user_request);

void* malloc(size_t size) {
  if(HEAP_START == NULL) { init_heap(); }
  size_t block_size = block_size_of(size);
  uint64_t* block_to_use = find_block(HEAP_START, block_size);
  if(block_to_use == NULL) {
    printf("Could not allocate %ld\n", block_size);
    return NULL;
  }
  split_block(block_to_use, block_size);
  void* addr_for_user = &block_to_use[1];
  return addr_for_user;
}

void free(void* ptr) {
  uint64_t* p = ptr;
  p[-1] = p[-1] & (~1);
}


uint64_t* find_block(uint64_t* start, size_t size) {
  int index = 0;
  while(index < HEAP_WORDS) {
    uint64_t current = start[index];
    if((current % 2 == 0) && current >= size) {
      return &start[index];
    }
    index += (current / 8);
  }
  return NULL;
}

void split_block(uint64_t* block_start, size_t size) {
  size_t current_block_size = block_start[0];
  if(current_block_size > size) {
    size_t busy_size = size;
    size_t free_size = current_block_size - size;
    block_start[0] = busy_size + 1;
    block_start[busy_size / 8] = free_size;
  }
  else if(current_block_size == size) {
    block_start[0] = size + 1;
  }
}

size_t block_size_of(size_t user_request) {
  return ((user_request + 7) & ~7) + 8;
}

