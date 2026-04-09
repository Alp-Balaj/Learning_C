#include <stdio.h>

int power(int m, int n);

int main(){
    int i;

    for(i = 0; i < 10; i++)
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    return 0;
}

// While learning about functions from the book I came across the concept of pass by value, and reference
// C Supports both of these, in the normal default sense it passes by value.
// If changes to the variable need to be done, you pass a pointer to that variable.
int power(int base, int n){
    int p;
    // Pass by value, allows us to use the n and make changes to it's value without effecting the variable that was passed to this function.
    for(p = 1; n > 0 ; n--)
        p = p * base;

    return p;
}
