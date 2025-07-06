#ifndef NGG_H
#define NGG_H

#define NGG_DIFFICULTY_COUNT 3
extern const int NGG_DIFFICULTY_CHANCES[NGG_DIFFICULTY_COUNT];
extern const char *NGG_DIFFICULTY_NAMES[NGG_DIFFICULTY_COUNT];

typedef struct {
    int random_number;
    int difficulty_level;
    int chances_left;
    int attempts;
    bool game_over;
} ngg_state;

#endif