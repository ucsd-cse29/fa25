#include <stdint.h>
#include <stdio.h>

#include "is_ascii_lessthan.c"
#include "is_ascii_bitand.c"

int main() {
  char input[5];
  fgets(input, 5, stdin);
  printf("Using <= %s\n", is_ascii_lessthan(input[0]) ? "true" : "false");
  printf("Using & == 0 %s\n", is_ascii_bitand(input[0]) ? "true" : "false");
}
