#pragma once
#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "Timer.h"

using namespace std;

//Screen Dimensions
#define SCREEN_WIDTH 512
#define SCREEN_HEIGHT 416

const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;
SDL_Rect rect{ 50, 50, 100, 100 };
int frame;
float speed = 1 * SCREEN_TICKS_PER_FRAME;

SDL_Renderer* renderer;
LTimer fpsTimer;
LTimer capTimer;

#endif