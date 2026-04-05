#include <stdio.h>

int main(){
    int fahr;

    for (fahr = 0; fahr <= 300; fahr += 20)
        printf("F: %3d \t C: %6.2f\n", fahr, (5.0 / 9.0) * (fahr - 32));
}
