#include <stdio.h>
#include <string.h>
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
}
