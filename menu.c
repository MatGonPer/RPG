#include "config.h"
#include "game_state.h"
#include "menu.h"

#define PLAY_BUTTON_WIDTH 125.0f

Texture2D play_button_texture;

//Função para carregar os recursos do estado
void InitMenu(void) {
    play_button_texture = LoadTexture("assets/graphics/ui/principal_menu/play_button.png");
}

//Função para liberar os recursos quando saímos do estado
void UnloadMenu(void) {
    UnloadTexture(play_button_texture);
}

void UpdateMenu(void) {
    //Captura a posição do mouse
    Vector2 mouse_position = GetMousePosition();

    float play_button_width = PLAY_BUTTON_WIDTH;
    float play_button_height = play_button_width * ((float)play_button_texture.height / (float)play_button_texture.width);

    Rectangle play_button_rec = {
        .x = (SCREEN_WIDTH / 2.0f) - (play_button_width / 2.0f),
        .y = (SCREEN_HEIGHT / 2.0f) - (play_button_height / 2.0f) + 50,
        .width = play_button_width,
        .height = play_button_height
    };

    //Checagem se o mouse clicou no botão play
    if(CheckCollisionPointRec(mouse_position, play_button_rec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        estado_atual = STATE_GAMEPLAY;
        estado_atual = STATE_GAMEPLAY;
    }
}

void RenderMenu(void) {
    ClearBackground(BLACK);

    const char *TITLE = "MEU RPG FANTASY";
    int font_size = 50;
    int title_measure = MeasureText(TITLE, font_size);
    int title_x = (SCREEN_WIDTH / 2.0F) - (title_measure / 2.0f);
    DrawText(TITLE, title_x, 100, font_size, WHITE);

    float play_button_width = PLAY_BUTTON_WIDTH;
    float play_button_height = play_button_width * ((float)play_button_texture.height / (float)play_button_texture.width);

    Rectangle play_button_source = {0, 0, (float)play_button_texture.width, (float)play_button_texture.height};
    Rectangle play_button_dest = {
        (SCREEN_WIDTH / 2.0f) - (play_button_width / 2.0f),
        (SCREEN_HEIGHT / 2.0f) - (play_button_height / 2.0f) + 50,
        play_button_width,
        play_button_height
    };
    DrawTexturePro(play_button_texture, play_button_source, play_button_dest, (Vector2){0, 0}, 0.0f, WHITE);
}
