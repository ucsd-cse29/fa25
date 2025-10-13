#include <stdio.h>
#include <string.h>

void concat(char* a, char* b, char* result) {
  printf("a: %p, b: %p\nresult: %p\n", a, b, result);
  int alen = strlen(a), blen = strlen(b);
  for(int i = 0; i < alen; i += 1) {
    result[i] = a[i];
  }
  for(int i = 0; i < blen; i += 1) {
    result[alen + i] = b[i];
  }
  result[alen + blen] = 0;
}

int main(int argc, char** argv) {
  printf("Argv: %p\n", argv);
  printf("Arg index 0: %p: %s\n", argv[0], argv[0]);
  printf("Arg index 1: %p: %s\n", argv[1], argv[1]);
  printf("Arg index 2: %p: %s\n", argv[2], argv[2]);

  char result[strlen(argv[1]) + strlen(argv[2]) + 1];
  concat(argv[1], argv[2], result);

  printf("%s\n", result);
}
