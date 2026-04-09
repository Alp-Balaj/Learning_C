#include <stdio.h>

#define MAXLINE 1000

// In functions where arrays are into play, C doesn't work as pass by value anymore, instead yes... the pointer to the first item in the array is passed by value.
// So a copy of the pointers value is passed down to the other function.
// But something to keep in mind is that the array itself now is exposed to the function, so the real place in memory where the array is can now be modified.
// So that happens in these two functions below.
int getLine(char line[], int maxLine);
void copy(char to[], char from[]);

int main(){
    int len, max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    // Keeps iterating reading new lines, nese length qe u lexu prej qasaj line.
    // It saves the max length
    // And also uses the function copy to copy over the line to the longest(char array variable declared)
    while((len = getLine(line, MAXLINE)) > 0)
        if(len > max) {
            max = len;
            copy(longest, line);
        }

    if(max > 0){
        printf("\nLongest line from the input is: %s\n", longest);
        printf("Number of characters in this line is: %d\n", max);
    }

    return 0;
}

int getLine(char s[], int lim){
    int c, i;

    // Faqin hell, qikjo po kqyr nese i eshte ma e vogel se MAXLINE(aka limitin)
    // Edhe nese character qe po bohet read nuk osht End Of File
    // Poashtu nese nuk eshte a new line character.
    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        // Perderi sa eshte tu i plotsu qito kushte
        // It continues saving the characters to the character array one by one.
        s[i] = c;

    // Qikjo e kqyr nese characteri i fundit saved ne variable a eshte new line, qe me shti ne array
    // Edhe e rrit vleren e i-se one more time
    // Kjo bohet se munet me ardh empty line veq me ni enter qe nuk i plotson kushtet paraprake me hi n'for loop.
    if(c == '\n'){
        s[i] = c;
        ++i;
    }

    // '\0' represents the end of the line.
    s[i] = '\0';
    // Returns the length of the line.
    return i;
}

void copy(char to[], char from[]){
    int i;

    i = 0;
    // Copies over character by character from the "from" array to the "to" array.
    while((to[i] = from[i]) != '\0')
        ++i;
}
