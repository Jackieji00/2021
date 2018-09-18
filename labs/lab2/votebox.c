#include <stdio.h>
#include <string.h>
<<<<<<< HEAD
int main(){
    int size;
    printf("Please input an integer value: ");
    scanf("%d", &size);
    char str[] = "-",*space = " ", result[size], *bslash = "\\",slash = "/";
    for(int c = 0;c<size;c++ ){
        printf("%s", str);
    }
    for(int i = 0;i<size-2;i++){
        printf("\n|");
        for(int add = 0;add<size-2;add++ ){
            if ((i==add)|){
                strcpy(result,bslash);
            } else if ()
            strcpy(result,space);
        }
        printf("%s",result );
        printf("|");
    }
    for(int c = 0;c<size;c++ ){
        printf("%s", str);
    }
=======
#include <stdlib.h>
void vote_box(int size){
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
}
int main() {
  int size;
  printf("Please input an integer value: " );
  scanf("%i\n",&size );
  vote_box(size);
>>>>>>> a9b3c7e4ffd058510ab33523937c87fd803cefbe
}
