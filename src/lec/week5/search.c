#include "str.h"
#include <string.h>
#include <stdio.h>


int main(int argc, char** argv) {
  String search;
  search.len = strlen(argv[1]);
  search.contents = argv[1];
  while(1) {
    String s = readline(1000);
    if(s.contents == NULL) { break; }
    if(contains(s, search)) {
      printf("%s\n", s.contents);
    }
  }
}

