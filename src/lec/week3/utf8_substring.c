#include <stdio.h>
#include <string.h>
#include <stdint.h>

int8_t cp_width(char b) {
  if((b & 0b10000000) == 0) { return 1; }
  if((b & 0b11100000) == 0b11000000) { return 2; }
  if((b & 0b11110000) == 0b11100000) { return 3; }
  if((b & 0b11111000) == 0b11110000) { return 4; }
  return -1;
}

int bi_for_cpi(char str[], int cpi) {
  int cur_bi = 0, cur_cpi = 0;
  while(str[cur_bi] != 0) {
    int width = cp_width(str[cur_bi]);
    cur_bi += width;
    cur_cpi += 1;
    if(cur_cpi == cpi) { return cur_bi; }
  }
  return -1;
}

void utf8_substring(char str[], int start, int end, char res[]) {
  int start_byte = bi_for_cpi(str, start);
  int end_byte = bi_for_cpi(str, end);
  printf("%d-%d in code points is %d-%d in bytes\n",
         cpi_start, cpi_end, start_byte, end_byte);
  for(int i = start_byte; i < end_byte; i += 1) {
    res[i - start_byte] = str[i];
  }
  res[end_byte - start_byte] = 0;
}

int main() {
  char buffer[100];
  printf("Enter a utf8 string: ");
  fgets(buffer, sizeof(buffer), stdin);
  char result[100];
  utf8_substring(buffer, 2, 6, result);
  printf("substring of %s from 2-6 is %s\n", buffer, result);
}

