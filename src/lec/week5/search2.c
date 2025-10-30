#include <string.h>
#include <stdio.h>


int main(int argc, char** argv) {
  char* search = argv[1];
  while(1) {
    char s[1000];
    char* result = fgets(s, 1000, stdin);
    if(result == NULL) { break; }
    if(strstr(s, search) != NULL) {
      printf("%s\n", s);
    }
  }
}
