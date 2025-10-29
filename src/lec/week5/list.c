#include <stdio.h>

#define MAX_LIST_SIZE 100000

// Most operating systems/processes set a STACK SIZE LIMIT
// A couple of megabytes on this computer
// Megabyte ~= 1,000,000 bytes

typedef struct ListOfDoubles {
  int size;
  double contents[MAX_LIST_SIZE];
} ListOfDoubles;

ListOfDoubles concat(ListOfDoubles d1, ListOfDoubles d2) {
  ListOfDoubles result;
  result.size = d1.size + d2.size;
  for(int i = 0; i < d1.size; i += 1) {
    result.contents[i] = d1.contents[i];
  }
  for(int i = 0; i < d2.size; i += 1) {
    result.contents[i + d1.size] = d2.contents[i];
  }
  return result;
}

int main() {
  ListOfDoubles lod = { 2, { 3.0, 4.0 } };
  ListOfDoubles lod2 = { 3, { 6.0, 9.0, 10.0 } };
  ListOfDoubles added = concat(lod, lod2);
  for(int i = 0; i < added.size; i += 1) {
    printf("%f ", added.contents[i]);
  }
  printf("\n");
}
