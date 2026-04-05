#include <stdio.h>

#define LOWER 0 // lower limit of the table defined as a constant before the main function
#define UPPER 300
#define STEP 20

int main(){
    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
        printf("F: %3d \t C: %6.2f\n", fahr, (5.0 / 9.0) * (fahr - 32));
}
