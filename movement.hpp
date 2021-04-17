#pragma once
#ifndef movement_hpp
#define movement_hpp 
#include <SDL2/SDL.h>
#include<SDL2/SDL.h>
#include <bits/stdc++.h>
using namespace std;

void moveleft()
{
    player.x=max(213,player.x-427);
}

void moveright()
{
    player.x=min(1007,player.x+427);
}

#endif
