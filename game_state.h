#ifndef GAME_STATE_H
#define GAME_STATE_H
#include "raylib.h"

typedef enum GameState {
    STATE_MENU,
    STATE_GAMEPLAY
} GameState;

extern GameState estado_atual;

#endif // GAMESTATE
