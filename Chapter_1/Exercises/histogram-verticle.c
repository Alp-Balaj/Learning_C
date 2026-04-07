#include <stdio.h>

#define IN 1;
#define OUT 0;
// The code for fetching the necessary data is the same as the horizontal histogram.
// With the exception of the longest word lenght.
int main(){
    int inWord = OUT;
    char buffer[1000];

    int c, charCounter, wordCounter, longestWord;
    int i, j, len;

    len = 0;
    wordCounter = 0;
    while ((c = getchar()) != EOF){
        buffer[len++] = c;
        if(c == ' ' || c == '\t' || c == '\n'){
            inWord = OUT;
        } else if (!inWord) {
            inWord = IN;
            wordCounter++;
        }
    }

    int wordIndexer[wordCounter];

    for (i = 0; i < wordCounter; ++i)
        wordIndexer[i] = 0;

    j = 0;
    charCounter = longestWord = 0;
    inWord = OUT;
    for (i = 0; i < len; i++){
        c = buffer[i];
        if(c == ' ' || c == '\t' || c == '\n'){
            if(inWord){
                wordIndexer[j] = charCounter;
                if(charCounter > longestWord)
                    longestWord = charCounter;
                charCounter = 0;
                j++;
                inWord = OUT;
            }
        }
        else{
            charCounter++;
            inWord = IN;
        }
    }

    // 9 | X 0 X X 0 X 0 0 X
    // 8 | X X X X 0 X 0 0 X
    // 7 | X X X X 0 X X 0 X
    // 6 | X X X X X X X 0 X
    // 5 | X X X X X X X X X
    // ...

    printf("\n");
    // start top to bottom, longest word and then compare it to the wordIndexer to see if I should add an X (in this case) for that row or not.
    for(j = longestWord; j > 0; j--){
        printf("%3d |   ", j);
        for(i = 0; i < wordCounter; i++){
            printf(wordIndexer[i] >= j? "X   " : "    ");
        }
        printf("\n");
    }

    // horizontal line to seperate the values from the indexes
    printf("    +---");
    for(i = 0; i < wordCounter; i++)
        printf("----");

    printf("\n");

    // printing indexes because why not...
    printf("    | ");
    for(i = 0; i < wordCounter; i++)
        printf("%3d ", i + 1);

    printf("\n");
}
