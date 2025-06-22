#include "config.h"
#include "game_state.h"
#include "menu.h"

#define PLAY_BUTTON_WIDTH 125.0f
#define EXIT_BUTTON_WIDTH 125.0f

static Texture2D play_button_texture;
static Texture2D exit_button_texture;

//Função para carregar os recursos do estado
void InitMenu(void) {
    play_button_texture = LoadTexture("assets/graphics/ui/principal_menu/play_button.png");
    exit_button_texture = LoadTexture("assets/graphics/ui/principal_menu/exit_button.png");
}

//Função para liberar os recursos quando saímos do estado
void UnloadMenu(void) {
    UnloadTexture(play_button_texture);
    UnloadTexture(exit_button_texture);
}

void UpdateMenu(void) {
    //Captura a posição do mouse
    Vector2 mouse_position = GetMousePosition();

    //Colisão para o botão play
    float play_button_width = PLAY_BUTTON_WIDTH;
    float play_button_height = play_button_width * ((float)play_button_texture.height / (float)play_button_texture.width);

    Rectangle play_button_rec = {
        (SCREEN_WIDTH / 2.0f) - (play_button_width / 2.0f),
        (SCREEN_HEIGHT / 2.0f) - (play_button_height / 2.0f) + 50,
        (float)play_button_width,
        (float)play_button_height
    };

    //Checagem se o mouse clicou no botão play
    if(CheckCollisionPointRec(mouse_position, play_button_rec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        atual_state = STATE_GAMEPLAY;
        atual_state = STATE_GAMEPLAY;
    }

    //Colisão para o botão exit
    float exit_button_width = EXIT_BUTTON_WIDTH;
    float exit_button_height = exit_button_width * ((float)exit_button_texture.height / (float)exit_button_texture.width);

    Rectangle exit_button_rec = {
        (SCREEN_WIDTH / 2.0f) - (exit_button_width / 2.0f),
        (SCREEN_HEIGHT / 2.0f) - (exit_button_height / 2.0f) + 150,
        (float)exit_button_width,
        (float)exit_button_height
    };

    //Checa se o mouse clicou no botão exit
    if(CheckCollisionPointRec(mouse_position, exit_button_rec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        game_should_close = 1;
    }
}

void RenderMenu(void) {
    ClearBackground(BLACK);

    //Titulo do jogo
    const char *TITLE = "MEU RPG FANTASY";
    int font_size = 50;
    int title_measure = MeasureText(TITLE, font_size);
    int title_x = (SCREEN_WIDTH / 2.0F) - (title_measure / 2.0f);
    DrawText(TITLE, title_x, 100, font_size, WHITE);

    //Desenhar o botão play
    float play_button_width = PLAY_BUTTON_WIDTH;
    float play_button_height = play_button_width * ((float)play_button_texture.height / (float)play_button_texture.width);

    Rectangle play_button_source = {0.0f, 0.0f, (float)play_button_texture.width, (float)play_button_texture.height};
    Rectangle play_button_dest = {
        (SCREEN_WIDTH / 2.0f) - (play_button_width / 2.0f),
        (SCREEN_HEIGHT / 2.0f) - (play_button_height / 2.0f) + 25,
        play_button_width,
        play_button_height
    };
    DrawTexturePro(play_button_texture, play_button_source, play_button_dest, (Vector2){0, 0}, 0.0f, WHITE);

    //Desenhar o botão exit
    float exit_button_width = EXIT_BUTTON_WIDTH;
    float exit_button_height = exit_button_width * ((float)exit_button_texture.height / (float)exit_button_texture.width);

    Rectangle exit_button_source = {0.0f, 0.0f, (float)exit_button_texture.width, (float)exit_button_texture.height};
    Rectangle exit_button_dest = {
        (SCREEN_WIDTH / 2.0f) - (exit_button_width / 2.0f),
        (SCREEN_HEIGHT / 2.0f) - (exit_button_height / 2.0f) + 150,
        (float)exit_button_width,
        (float)exit_button_height
    };

    DrawTexturePro(exit_button_texture, exit_button_source, exit_button_dest, (Vector2){0.0f,0.0f}, 0.0f, WHITE);
}
