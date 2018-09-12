#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
  int size;
  printf("Please input an integer value: " );
  scanf("%i\n",&size );
  for(int i = 0;i<size;i++){
      printf("-");
  }
  for(int c=0;c<size-2;c++){
    // printf("\n%i,%i,%i,%i", size,c,size/2-1,c);
    printf("\n|" );
    if (size%2==1&&c%2==0&&c==size/2-1){
      for(int add=0;add<(size-2);add++){
        if(c==add){
          printf("x");
        }else{
          printf(" " );
        }
      }
      printf("|" );
    }else{
      for(int add=0;add<(size-2);add++){
        if(c==add){
          printf("\\");
        }else if (abs(size-3-add)==c){
          printf("/" );
        }else{
          printf(" " );
        }
      }
      printf("|" );
    }
  }
  printf("\n");
  for(int i = 0;i<size;i++){
      printf("-");
  }
  printf("\n" );
  return 0;
}
