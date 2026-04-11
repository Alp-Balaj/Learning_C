#include <stdio.h>

#define MAXLINE 1000    // maximum input line size

int max;                // maximum length seen so far
char line[MAXLINE];     // current input line
char longest[MAXLINE];  // longest line saved here

int getLine(void);      // compared to the same function beforehand, this requires no parameters to be passed to be used.
void copy(void);        // same with the copy function, since the variables needed are external.

int main(){
    int len;
    // the extern in this case is redundant but, since it's the first time using it I will keep it here.
    // the idea behind the external variables, and when declaring them inside functions as extern, is basicaly telling the compiler that there exists a case where the variable is declared... just let me use it in the function. AKA don't throw an error for it.
    // while usually the correct way to be using these is to collect all of these external variables, in a seperate file called a header.
    extern int max;
    extern char longest[];

    max = 0;
    // this while keeps going as long as the line fetched from the getline function is bigger than 0
    while((len = getLine()) > 0)
        // it then is cross checked with the max length, to repleace it if neccessary, and copy it over to the variable responsible for saving the line itself.
        if(len > max){
            max = len;
            copy();
        }

    // after the while loop ends it checks if any input has been valid... aka longer than 0
    if(max > 0)
        printf("%s", longest);
    return 0;
}

int getLine(void){
    int c, i;
    extern char line[];

    for(i = 0; i < MAXLINE - 1
        && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;

    if(c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';

    // returns the length of the line read,
    // and also saves the line to the external variable in turn throughout the function itself.
    return i;
}

void copy(void){
    int i;
    extern char line[], longest[];

    i = 0;
    while((longest[i] = line[i]) != '\0')
        i++;
}
