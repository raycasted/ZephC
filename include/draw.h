#pragma once
#include "init.h"
#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include <SDL_pixels.h>
void GameDraw(SDL_Renderer *renderer, gameInfo ginfo) {
  //(void)renderer;
  // Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.
  // Set render color to blue ( rect will be rendered in this color )
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

  // Render rect
  SDL_RenderDrawRect(renderer, &ginfo.player);
}
