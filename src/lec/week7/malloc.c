#include "malloc.h"
#include <unistd.h>

void* HEAP_START = NULL;

void init_malloc_heap() {
  HEAP_START = sbrk(80000);
}

void* mymalloc(int size) {
  if(HEAP_START == NULL) { init_malloc_heap(); }
  ...
}

void myfree(void* ptr) {
  return;
}
