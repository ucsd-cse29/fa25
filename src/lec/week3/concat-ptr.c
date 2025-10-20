#include <stdio.h>
#include <string.h>

char* concat(char a[], char b[]) {
  int alen = strlen(a), blen = strlen(b);
  char result[alen + blen + 1];
  for(int i = 0; i < alen; i += 1) {
    result[i] = a[i];
  }
  for(int i = 0; i < blen; i += 1) {
    result[i + alen] = b[i];
  }
  result[alen + blen] = 0;
  char* returnPtr = result;
  return returnPtr;
}

int main() {
  char like[] = "I like ";
  char c1[] = "apples";
  char c2[] = "CSE29";

  printf("like: %p c1: %p c2: %p\n", like, c1, c2);

  char* result1 = concat(like, c1);
  char* result2 = concat(like, c2);
  printf("%p %s\n", result1, result1);
  printf("%p %s\n", result1, result2);

}
