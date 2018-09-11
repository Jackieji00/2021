#include <stdio.h>
#include <math.h>

int main() { /* note the int return designation on main() */
    int x = 100;
    int y = 200;
    int total = x + y;
    printf("\nWelcome to Lab 2\n");
    printf("\nThe sum of %i and %i is: %i", x, y, total);
    printf("\nOr another way: ");
    printf("\nThe sum of %i and %i is: %i", x, y, x + y);
    printf("\nOK\n");

    printf("integer   square root\n" );
    for (int i =1; i <=15;i++ ) {
        printf("%i         %10.2f\n",i,sqrt(i));
    }
}
