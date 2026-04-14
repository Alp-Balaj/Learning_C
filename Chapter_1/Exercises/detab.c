#include <stdio.h>

#define TABSTOP 4
#define MAXLINE 1000

char line[MAXLINE];
char formatedString[MAXLINE]; // The string that will be printed in the end, I guess...

int stringCount = 0; // Index for the formated string, I guess...

int getLine(void);
int replace(int index);
void append(void);

int main(){
    int counter = 1;
    while(getLine() != 0)
        append();

    printf("%s\n", formatedString);
}

int getLine(void){
    int c, i, jump;

    for(i = 0; i < MAXLINE - 1
        && (c = getchar()) != EOF && c != '\n'; i++)
    {
        // if find tab, tab go bye-bye
        if(c == '\t')
            i = replace(i);
        else
            line[i] = c;
    }

    if(c == '\n') {
        line[i] = c;
        i++;
    }

    line[i] = '\0';

    return i;
}

int replace(int index){
    int spaces, j;
    // this sees how many spaces have already been added to this column
    spaces = index % TABSTOP;

    // this counts backwards compared to the spaces already existing.
    // 3 spaces existing, it will be adding 5 more spaces counting backwards
    for(j = TABSTOP; spaces < j; j--){
        line[index++] = ' ';
    }

    // -1 because in the last incrementation of the index we pass a spot and we don't give it value.
    // Therefore when passing back the index where the buffering should continue we continue from the index where the last value was placed, even though we skip that
    // There has to be a better way to handle this but so be it... for now.
    return index - 1;
}

void append(void){
    int i;

    i = 0;
    while((formatedString[stringCount] = line[i]) != '\0'){
        i++;
        stringCount++;
    }
}
