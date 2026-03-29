#include <stdio.h>

int main(int argc, char** argv)
{
    printf("hello ");
    for(int i = 1; i < argc; i++){
        if(i == argc-1){
            printf("and %s!\n", argv[i]);
            break;
        }
        printf("%s, ", argv[i]);
    }
}
