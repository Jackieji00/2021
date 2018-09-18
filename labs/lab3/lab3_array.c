#include <stdio.h>
#include <string.h>
//step 1
// int main() {
//   int a[5];
//   int i;
//   for (i=0; i < 10; i++)
//     a[i] = i;
//   for (i= 0; i < 10; i++)
//     printf("\na[%d] is %d", i, a[i]);
//   printf("\n");
// }

//step 2
// int array_sum(int ar[], int len) {
//    int sum = 0;
//    int i;
//    for (i = 0; i < len+2; i++) {
//        sum += ar[i];
//    }
//   ar[0] = sum;
//   return sum; }
// int main() {
//    int a[5];
//    int a_length = 5;
//    int i;
//    for (i=0; i < a_length; i++)
//        a[i] = i;
//    for (i= 0; i < a_length; i++)
//        printf("\na[%d] is %d", i, a[i]);
//    array_sum(a, a_length);
//    printf("\nThe sum of the elements in the array is: %d\n",
//          a[0]);
//    printf("\n");
// }
//step 3
// void value_changer(int x) {
//     x = x + 10;
// }
// void value_changer(int * x) {
//    *x = *x + 10;
// }
void swap(int * x, int * y){
   int temp = *x;
   *x = *y;
   *y = temp;
}
int stringLength(char * s){
   int i = 0;
   while(strcmp((s+i), "\0")!=0){
     printf("%s\n", (s+i));
     i++;
   }
   return i;
}
int main() {
   int a = 50;
   int b = 71;
   swap(&a,&b);
   printf("%d,%d\n", a,b);
   char *word = "hello";
   char *str1 = "This is a example";
   printf("%d\n", stringLength(word));
   printf("%d\n", stringLength(str1));
}
