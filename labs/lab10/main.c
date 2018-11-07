#include <stdio.h>
extern int proc1(int x, int y);
int main() {
  int x = 3, y = 5;
  printf("\nValue of %d + %d is %d\n", x, y, proc1(x, y));
}
