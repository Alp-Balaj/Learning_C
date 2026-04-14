#include <stdio.h>

#define TABSTOP 8
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
    int c, i;

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
    spaces = index % 8;

    // this counts backwards compared to the spaces already existing.
    // 3 spaces existing, it will be adding 5 more spaces counting backwards
    for(j = 8; spaces < j; j--)
        line[index++] = ' ';

    printf("index: %d\n", index);
    return index;
}

void append(void){
    int i;

    i = 0;
    // while((formatedString[stringCount] = line[i]) != '\0'){
    while(i != 45){
        if(line[i] == '\0')
            printf("why am i here!?");
        printf("ch: %c\n", line[i]);
        i++;
        stringCount++;
    }


}
