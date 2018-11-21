#include <stdio.h>
extern int proc1(int x, int y);
extern int sum_of_squares(int x, int y);
extern int return_larger(int x, int y);
int main() {
  int x = 3, y = 5;
  printf("\nValue of %d + %d is %d\n", x, y, proc1(x, y));
  printf("\nValue of %d^2 + %d^2 is %d\n", x, y, sum_of_squares(x, y));
  printf("\nLarger Value of %d and %d is %d\n", x, y, return_larger(x, y));
}
