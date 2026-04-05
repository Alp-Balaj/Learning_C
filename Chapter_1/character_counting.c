#include <stdio.h>

int main(){
    // Again the easy way to be counting the characters on the input
    // long counter;

    // counter = 0;
    // while (getchar() != EOF)
    //     ++counter;
    // printf("%ld\n",counter);

    // Whereas the more professional way to so... Fucking interesing
    double counter;

    for (counter = 0; getchar() != EOF; ++counter);

    printf("%.0f\n", counter);
}
