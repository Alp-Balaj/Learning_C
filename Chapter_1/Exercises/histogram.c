#include <stdio.h>
int main(){
    int c, i, j, charCounter, wordCounter;
    charCounter = wordCounter = 0;

    char buffer[1000];
    int len = 0;

    // I'm trying to find out how many words there is in the input.
    // As well as save the data to a buffer to be using it later on.
    while ((c = getchar()) != EOF){
        buffer[len++] = c;
        if(c == ' ' || c == '\t' || c == '\n')
            wordCounter++;
    }

    // Create an array that will hold the indexes of the amount of words that were found before hand.
    int wordIndexer[wordCounter];

    // Filling the array me 0
    for (i = 0; i < wordCounter; ++i)
        wordIndexer[i] = 0;

    // Loop through this shit again, to find out the length of the words, to fill out the array.
    j = 0;
    for (i = 0; i < len; i++){
        // Read from the buffer.
        c = buffer[i];
        if(c == ' ' || c == '\t' || c == '\n'){
            // Once I find the spaces, I lock in the number of the characters to that place in the array.
            // And reset the charCounter, for the next set of characters.
            wordIndexer[j] = charCounter;
            charCounter = 0;
            j++;
        }
        else{
            charCounter++;
        }
    }

    j = 0;
    // This should be the printing function... if this shit works, and the data is correct beforehand.
    for(i = 0; i < wordCounter; i++){
        printf("%d:\t", i);

        if(wordIndexer[i] == 0)
            printf("\n");
        // printf("Word nr: %d,\twordIndexerValue: [ %d ]\n", i, wordIndexer[i]);
        for (j = 0; j < wordIndexer[i]; j++){
            if(j == wordIndexer[i] - 1)
                printf("-\n");
            else
                printf("-");
        }
    }
}
