#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define RANDINT rand()%900 + 100

char* getClues(char guess[], char secret[]){
    /**
     * Returns a string with the Pico Fermi Bagels clues for a guess and secret number pair.
     */
    char *clues = (char*)calloc(50, sizeof(char));
    for(int i=0; i< strlen(guess); i++){
        if(guess[i] == secret[i]){
            strcat(clues, " Fermi ");
        }
        else {
            for(int j=0; j< strlen(secret); j++){
                if(guess[i] == secret[j]){
                    strcat(clues," Pico ");
                }
            }
        }        
    }
    if(strlen(clues) == 0){
        strcat(clues, " Bagels ");
    }

    return clues;
}
int main(int argc, char const *argv[])
{
    printf("Bagels, a deductive logic game.\n");
    printf("I am thinking of a 3-digit number. Try to guess what it is.\n");
    printf("Here are some clues:\n");
    printf("When I say:\tThat means:\n");
    printf("  Pico\t\tOne digit is correct but in the wrong position.\n");
    printf("  Fermi\t\tOne digit is correct and in the right position.\n");
    printf("  Bagels\tNo digit is correct.\n");
    printf("I have thought up a number.\n You have 10 guesses to get it.\n");

    int guesscount = 0;
    const int NUM_DIGITS = 3;
    const int MAX_GUESSES = 10;
    char guess[NUM_DIGITS + 1];
    char secret[NUM_DIGITS + 1];
    char *clues;
    while(1){
        int secretnumber = RANDINT;
        guesscount = 1;
        while(guesscount <= MAX_GUESSES){
            printf("Guess %d: \n> ", guesscount);
            scanf("%s", guess);
            sprintf(secret, "%d", secretnumber);
            if(strcmp(guess, secret) == 0){
                printf("Congratulations! You guessed it!\n");
                break;
            }
            clues = getClues(guess, secret);
            printf("%s\n", clues);
            guesscount++;
            fgets(guess, NUM_DIGITS + 1, stdin);
            free(clues);
        }
        if(guesscount > MAX_GUESSES){
            printf("You ran out of guesses. The answer was %s\n", secret);
        }
        printf("\nDo you want to play again? (yes or no)\n");
        char playagain[4];
        fflush(stdin);
        scanf("%s", playagain);
        if(strcmp(playagain, "no") == 0){
            break;
        }
    }
    printf("Thanks for playing!\n");
    return 0;
}
