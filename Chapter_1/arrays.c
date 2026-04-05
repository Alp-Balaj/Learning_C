#include <stdio.h>
int main(){
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;

    // Filling the array me 0
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;

    // Reads through the input

    while ((c = getchar()) != EOF)
        // If the character is between 0 and 9 #as character values, it increases the value of the array on c - '0'
        // Now why does that work? '0' has the value of 48 while let's take for example '3' has the value of 51
        // 51 - 48 => 3 ... which symbolizes the correct placement on the array for that digit...
        if(c >= '0' && c <= '9')
            ++ndigit[c-'0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;

    printf("digits =");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);

    printf(", white space = %d, other = %d\n", nwhite, nother);
}
