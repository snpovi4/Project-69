#pragma once
#ifndef structure_hpp
#define structure_hpp 
#include <SDL2/SDL.h>
#include<SDL2/SDL.h>
#include <bits/stdc++.h>
using namespace std;

struct renderwindow
{
	SDL_Renderer *renderer;
	SDL_Window *window;
    int fire;
}app;

struct Entity
{
	int x;
	int y;
    int dx,dy,health;
	SDL_Texture *texture;
} player,bullet;

#endif
