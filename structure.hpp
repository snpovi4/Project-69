#pragma once
#ifndef structure_hpp
#define structure_hpp 
#include <SDL2/SDL.h>
#include<SDL2/SDL.h>
#include <bits/stdc++.h>
using namespace std;

struct App
{
	SDL_Renderer *renderer;
	SDL_Window *window;
    int up,down,left,right;
	int keyboard[MAX_KEYBOARD_KEYS];
}app;

struct Entity
{
	int x;
	int y;
    int dx,dy,health,reload;
	SDL_Texture *texture;
} player;
vector<Entity>bullet;

#endif
