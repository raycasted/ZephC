/*
 * Copyright (c) 2018, 2019 Amine Ben Hassouna <amine.benhassouna@gmail.com>
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any
 * person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the
 * Software without restriction, including without
 * limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software
 * is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice
 * shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF
 * ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
 * SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
 * IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

#include <SDL_events.h>
#include <SDL_keycode.h>
#include <SDL_video.h>
#include <stdbool.h>
#include <stdio.h>

#include "draw.h"
#include "init.h"
#include "update.h"
#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include <SDL_image.h>
// Define MAX and MIN macros
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

// Define screen dimensions
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(int argc, char *argv[]) {
  // Unused argc, argv
  (void)argc;
  (void)argv;
  gameInfo ginfo;
  ginfo.player.x = 50;
  ginfo.player.y = 50;
  ginfo.player.w = 50;
  ginfo.player.h = 50;
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not be initialized!\n"
           "SDL_Error: %s\n",
           SDL_GetError());
    return 0;
  }

#if defined linux && SDL_VERSION_ATLEAST(2, 0, 8)
  // Disable compositor bypass
  if (!SDL_SetHint(SDL_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR, "0")) {
    printf("SDL can not disable compositor bypass!\n");
    return 0;
  }
#endif

  // Create window
  SDL_Window *window = SDL_CreateWindow(
      "Basic C SDL project", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
      SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (!window) {
    printf("Window could not be created!\n"
           "SDL_Error: %s\n",
           SDL_GetError());
  } else {
    // Create renderer
    SDL_Renderer *renderer =
        SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
      printf("Renderer could not be created!\n"
             "SDL_Error: %s\n",
             SDL_GetError());
    } else {

      // Event loop exit flag
      // bool quit = false;

      // Game loop
      while (true) {
        SDL_Event e;

        // Wait indefinitely for the next available event
        SDL_WaitEvent(&e);

        // User requests quit
        if (e.type == SDL_QUIT) {
          break;
        }
        // Handle user input
        if (e.type == SDL_KEYDOWN) {
          // printf("huh");
          if (e.key.keysym.sym == SDLK_RIGHT) {
            // printf("WHY???");
            ginfo.player.x += 5;
          }
          if (e.key.keysym.sym == SDLK_ESCAPE) {
            break;
          }
        }

        GameUpdate(renderer);

        // Initialize renderer color white for the background
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

        // Clear screen
        SDL_RenderClear(renderer);

        GameDraw(renderer, ginfo);

        // Update screen
        SDL_RenderPresent(renderer);
        printf("loop");
      }

      // Destroy renderer
      SDL_DestroyRenderer(renderer);
    }

    // Destroy window
    SDL_DestroyWindow(window);
  }

  // Quit SDL
  SDL_Quit();

  return 0;
}
