#pragma once
#ifndef init_hpp
#define init_hpp 
#include <SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_timer.h>
#include <bits/stdc++.h>
using namespace std;

void initSDL(void)
{
	int rendererFlags, windowFlags;
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
	rendererFlags = SDL_RENDERER_ACCELERATED;

	windowFlags = 0;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout<<"Couldn't initialize SDL: "<<SDL_GetError()<<endl;
		exit(1);
	}

	app.window = SDL_CreateWindow("Falcon 6T : Knight", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

	if (!app.window)
	{
		printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
		exit(1);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);

	if (!app.renderer)
	{
		cout<<"Failed to create renderer: "<<SDL_GetError()<<endl;
		exit(1);
	}
}

#endif
