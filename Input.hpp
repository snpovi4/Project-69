#pragma once
#ifndef Input_hpp
#define Input_hpp 
#include <SDL2/SDL.h>
#include<SDL2/SDL.h>
#include <bits/stdc++.h>
#include "movement.hpp"
using namespace std;

void doInput(void)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_LEFT:
                    moveleft();
                    break;
                case SDLK_RIGHT:
                    moveright();
                default:
                    break;
                }
                break;
			case SDL_QUIT:
				exit(0);
				break;

			default:
				break;
		}
	}
}

#endif
