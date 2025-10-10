#include <string.h>
#include <stdio.h>

// Takes two strings a and b, and changes result to have the concatenation of a
// and b stored in it

// ASSUMES that result has length ____________________________________
void concat(char a[], char b[], char result[]) {
  int alen = strlen(a), blen = strlen(b);
  for(int i = 0; i < alen; i += 1) {
    result[i] = a[i];
  }
  for(int i = 0; i < blen; i += 1) {





  }




}


int main() {
  char str1[] = "Hello ";
  char str2[] = "CSE29";

  char result[                ];

  concat(str1, str2, result);

  printf("%s\n", result);




}
