#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  char* search = argv[1];
  while(1) {
    char* s = malloc(1000);
    char* result = fgets(s, 1000, stdin);
    if(result == NULL) { break; }
    if(strstr(s, search)) {
      printf("%s\n", s);
    }
  }
}

