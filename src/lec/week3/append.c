#include <string.h>
#include <stdio.h>

// Takes two double arrays a and b, and changes result to have the
// appended array of a and b stored in it

// ASSUMES that result has enough space
void append(double a[], double b[], double result[]) {

















}

void print_list(double lst[], int howmany) {
  for(int i = 0; i < howmany; i += 1) {
    printf("%f ", lst[i]);
  }
  printf("\n");
}


int main() {
  double n1[] = { 4.0, 5.0, 6.0 };
  double n2[] = { 0.7, 0.3, 0.1, 0.8 };
  double result[7];

  append(n1, n2, result);

  print_list(n1, 3);
  print_list(n2, 4);
}
