#include "str.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

String readline(int max_len) {
  char* contents = malloc(max_len);
  char* result = fgets(contents, max_len, stdin);
  String s;
  if(result == NULL) {
    s.len = 0;
    s.contents = NULL;
  }
  else {
    s.len = strlen(contents);
    s.contents = contents;
  }
  return s;
}

uint8_t contains(String haystack, String needle) {
  return strstr(haystack.contents, needle.contents) != NULL;
}

