#include "game_state.h"
#include "gameplay.h"

void UpdateGameplay(void) {
    if(IsKeyPressed(KEY_ESCAPE)) {
        atual_state = STATE_MENU;
    }
}

void RenderGameplay(void) {
    ClearBackground(BLACK);
    DrawText("Tela de jogo - Pressione ESC para voltar", 100, 250, 25, WHITE);
}
