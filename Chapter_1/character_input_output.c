#include <stdio.h>

// Copy paste, what you write in the terminal
int main(){
    int c;

    // Easy way to write this function...
    // c = getchar();
    // while(c != EOF){
    //     putchar(c);
    //     c = getchar();
    // }

    // A little more experience gets you this...
    while ((c = getchar()) != EOF)
        putchar(c);
}
