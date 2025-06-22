#include "game_state.h"
#include "gameplay.h"
#include "config.h"

//Array 2D que será o tilemap do mundo
static const int map[MAP_HEIGHT_IN_TILES][MAP_WIDTH_IN_TILES] = {
    // 0 = Grama, 1 = Terra, 2 = Água
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,2,2,2,2},
    {2,2,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,1,0,0,0,2,2},
    {2,0,0,0,1,1,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,0,0,0,2},
    {2,0,0,1,1,1,1,0,0,0,1,1,1,1,1,0,0,0,0,1,0,0,0,0,2},
    {2,0,0,0,1,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,2},
    {2,0,0,0,0,0,1,1,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,0,2},
    {2,0,0,0,0,1,1,1,1,0,0,0,1,1,1,0,0,0,0,1,1,1,1,0,2},
    {2,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,2},
    {2,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,2},
    {2,0,0,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,2},
    {2,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,2},
    {2,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,2},
    {2,0,1,1,0,1,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,2},
    {2,2,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,2,2},
    {2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}
};

//Textura do tileset do mundo
static Texture2D tileset_texture;

void InitGameplay(void) {
    tileset_texture = LoadTexture("assets/graphics/tilesets/tileset.png");
}

void UnloadGameplay(void) {
    UnloadTexture(tileset_texture);
}

void UpdateGameplay(void) {
    if(IsKeyPressed(KEY_ESCAPE)) {
        atual_state = STATE_MENU;
    }
}

void RenderGameplay(void) {
    //Fundo preto para o mundo
    ClearBackground(BLACK);

    //Configura a câmera do jogo
    //Camera2D camera = {0};
    //camera.zoom = 1.0f;
    //BeginMode2D(camera);

    //Percore o array onde está os tiles do mapa e desenha-os na tela
    for(int y = 0; y < MAP_HEIGHT_IN_TILES; y++) {
        for(int x = 0; x < MAP_WIDTH_IN_TILES; x++) {
            int tile_id = map[y][x];
            Rectangle tileset_source = {0.0f, (float)(tile_id * TILE_SIZE), (float)TILE_SIZE, (float)TILE_SIZE};
            Rectangle tileset_dest = {(float)(x * TILE_SIZE), (float)(y * TILE_SIZE), (float)TILE_SIZE, (float)TILE_SIZE};
            DrawTexturePro(tileset_texture, tileset_source, tileset_dest, (Vector2){0.0f, 0.0f}, 0.0f, WHITE);
        }
    }

    //EndMode2D();
}
