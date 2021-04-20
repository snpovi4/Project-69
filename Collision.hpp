#pragma once
#ifndef Collision_hpp
#define Collision_hpp 
#include <SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_timer.h>
#include <bits/stdc++.h>
using namespace std;

bool collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
	return (max(x1, x2) < min(x1 + w1, x2 + w2)) && (max(y1, y2) < min(y1 + h1, y2 + h2));
}
#endif