#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "config.h"
#include "game_state.h"
#include "menu.h"
#include "gameplay.h"

GameState atual_state;
bool game_should_close = 0;

int main(void) {
    //Configurações para a janela
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "RPG Fantasy");
    SetWindowMinSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    SetWindowMaxSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    SetTargetFPS(60);
    SetExitKey(KEY_NULL);

    //Carrega os recursos do estado menu
    InitMenu();

    //Estado inicial que o jogo se encontra
    atual_state = STATE_MENU;

    //Game loop
    while(!WindowShouldClose() && !game_should_close) {
        //Update
        switch(atual_state) {
            case STATE_MENU:
                UpdateMenu();
                break;
            case STATE_GAMEPLAY:
                UpdateGameplay();
                break;
            default:
                break;
        }

        //Render
        BeginDrawing();
        switch(atual_state) {
            case STATE_MENU:
                RenderMenu();
                break;
            case STATE_GAMEPLAY:
                RenderGameplay();
                break;
            default:
                break;
        }
        EndDrawing();
    }

    UnloadMenu();
    CloseWindow();

    return 0;
}
