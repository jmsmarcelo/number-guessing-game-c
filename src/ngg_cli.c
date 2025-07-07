#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/ngg_cli.h"
#include "../include/ngg.h"
#include "../include/ngg_utils.h"

void difficulty_selection(ngg_state *);
int read_int(const char *, int, int);
void play_again_prompt(bool *);

int ngg_start_cli() {
    ngg_state game_state;

    printf("\nWelcome to the Number Guessing Game!\n\n");

    difficulty_selection(&game_state);

    game_state.game_over = false;

    printf("\nGreat! You have selected the %s difficulty level.\n", NGG_DIFFICULTY_NAMES[game_state.difficulty_level - 1]);
    while(!game_state.game_over) {
        printf("\nI'm thinking of a number between 1 and 100.\n");
        game_state.random_number = random_number(1, 100);
        game_state.chances_left = NGG_DIFFICULTY_CHANCES[game_state.difficulty_level - 1];
        game_state.attempts = 0;
        printf("You have %d chances to guess the number.\n\n", NGG_DIFFICULTY_CHANCES[game_state.difficulty_level - 1]);
        printf("Let's start the game!\n\n");

        while(game_state.chances_left > 0) {
            int guess = read_int("Enter your guess: ", 1, 100);
            game_state.attempts++;
            game_state.chances_left--;

            if(guess == game_state.random_number) {
                printf("\nCongratulations! You guessed the correct number in %d attempts!\n", game_state.attempts);
                game_state.chances_left = 0;
                game_state.attempts = 0;
                continue;
            } else if(guess < game_state.random_number) {
                printf("Incorrect!\nThe number is greater than %d.\n", guess);
            } else {
                printf("Incorrect!\nThe number is less than %d.\n", guess);
            }
            if(game_state.chances_left == 0) {
                printf("\nSorry. you've run out of chances.\n");
            } else if(game_state.chances_left == 1) {
                const char *tip = (game_state.random_number % 2 == 0) ? "even" : "odd";
                printf("The number is %s.\n\n", tip);
            } else {
                printf("\n");
            }
        }
        play_again_prompt(&game_state.game_over);
    }

    return 0;
}

void difficulty_selection(ngg_state *game_state) {
    int difficulty_count = sizeof(NGG_DIFFICULTY_CHANCES) / sizeof(NGG_DIFFICULTY_CHANCES[0]);
    printf("Choose a difficulty level:\n");;;
    for(int i = 0; i < difficulty_count; i++) {
        printf(" %d. %s (%d chances)\n", i + 1, NGG_DIFFICULTY_NAMES[i], NGG_DIFFICULTY_CHANCES[i]);
    }
    game_state->difficulty_level = read_int("\nEnter your choice: ", 1, difficulty_count);
}
int read_int(const char *prompt, int min, int max) {
    char buffer[64];
    int value;
    while(1) {
        printf("%s", prompt);
        if(!fgets(buffer, sizeof(buffer), stdin)) {
            printf("Error reading input. Please try again.\n");
            continue;
        }
        buffer[strcspn(buffer, "\n")] = 0;
        char *endptr;
        value = strtol(buffer, &endptr, 10);
        if(endptr == buffer || *endptr != '\0') {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        if(value < min || value > max) {
            printf("Value must be between %d and %d.\n", min, max);
            continue;
        }
        return value;
    }
}
void play_again_prompt(bool *game_over) {
    char buffer[16];
    while(1) {
        printf("\nWould you like to play again? (y/n): ");
        if(!fgets(buffer, sizeof(buffer), stdin)) {
            printf("Error reading input.\n");
            continue;
        }
        buffer[strcspn(buffer, "\n")] = 0;
        if(strlen(buffer) == 1 && (buffer[0] == 'y' || buffer[0] == 'Y' || buffer[0] == 'n' || buffer[0] == 'N')) {
            if(buffer[0] == 'n' || buffer[0] == 'N') {
                *game_over = true;
                printf("\nThank you for playing! Goodbye!\n");
            }
            break;
        }
        printf("Invalid input. Please enter 'y' or 'n'.\n");
    }
}