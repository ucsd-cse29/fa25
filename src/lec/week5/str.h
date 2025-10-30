#ifndef STRING_H
#define STRING_H

#include <stdint.h>

typedef struct String {
  int len;
  char* contents;
} String;

String readline(int max_len);
uint8_t contains(String haystack, String needle);

#endif
