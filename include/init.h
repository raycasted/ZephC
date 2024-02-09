#pragma once
#include <SDL.h>
// Core game info
struct gameInfo {
  SDL_Rect player;
  SDL_Texture* playerTex;
  float playerXvel;
};
typedef struct gameInfo gameInfo;
