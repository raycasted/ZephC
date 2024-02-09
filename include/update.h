#pragma once
#include "init.h"
#include <SDL2_gfxPrimitives.h>
#include <SDL_keycode.h>
#include <SDL_pixels.h>
#include <SDL_video.h>
#include <stdbool.h>
#include <stdio.h>

#include <SDL.h>
#include <SDL_image.h>

void GameUpdate(SDL_Renderer *renderer) {
  // temporary fix for cmake's complaints (just trashes the renderer variable)
  (void)renderer;
}
