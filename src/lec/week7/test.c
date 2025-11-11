#include "malloc.h"
#include <stdio.h>

int main() {
  char* a = malloc(10);
  char* b = malloc(37);
  int* c = malloc(7 * sizeof(int));
  printf("After allocating a, b, c:\n");
  print_heap();
  free(b);
  int* d = malloc(5 * sizeof(int));
  printf("\nAfter freeing b and allocating d:\n");
  print_heap();
}
