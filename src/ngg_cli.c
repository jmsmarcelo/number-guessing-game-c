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
    return 0;
}

void difficulty_selection(ngg_state *game_state) {
    int difficulty_count = sizeof(NGG_DIFFICULTY_CHANCES) / sizeof(NGG_DIFFICULTY_CHANCES[0]);
    printf("Choose a difficulty level:\n");;;
    for(int i = 0; i < difficulty_count; i++) {
        printf(" %d. %s (%d chances)\n", i + 1, NGG_DIFFICULTY_NAMES[i], NGG_DIFFICULTY_CHANCES[i]);
    }
    game_state->difficulty_level = read_int("Enter your choice: ", 1, difficulty_count);
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
        buffer[strcspn(buffer, '\n')] = 0;
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
        buffer[strcspn(buffer, '\n')] = 0;
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