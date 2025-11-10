#include "malloc.h"
#include <stdio.h>

int main() {
  char* a = mymalloc(40);
  char* b = mymalloc(24);
  char* c = mymalloc(80);

  printf("%p %p %p\n", a, b, c);
}
