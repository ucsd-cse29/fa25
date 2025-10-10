#include <stdio.h>
#include <string.h>


void concat(char* a, char* b, char* result) {
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
  printf("some args: %s, %s, %s\n", argv[0], argv[1], argv[2]);

  char result[strlen(argv[1]) + strlen(argv[2]) + 1];
  concat(argv[1], argv[2], result);

  printf("%s\n", result);
}
