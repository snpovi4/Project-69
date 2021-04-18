#pragma once
#ifndef movement_hpp
#define movement_hpp 
#include <SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include <bits/stdc++.h>
#include "draw.hpp"
using namespace std;

static void fireBullet(void)
{
    Entity temp_bullet;
    memset(&temp_bullet,0,sizeof(Entity));
    temp_bullet.x = player.x+35;
    temp_bullet.y = player.y;
    temp_bullet.health=1;
    temp_bullet.dx=0;
    temp_bullet.dy= - PLAYER_BULLET_SPEED;
    temp_bullet.texture = loadTexture("bullet_level_1.png");
    temp_bullet.x+=temp_bullet.dx;
    temp_bullet.y+=temp_bullet.dy;
    bullet.push_back(temp_bullet);
    player.reload=8;
}

void movePlayer()
{
    player.dx = player.dy = 0;

	if (player.reload > 0)
	{
		player.reload--;
	}

	if (app.keyboard[SDL_SCANCODE_UP])
	{
		player.dy = -PLAYER_SPEED;
	}

	if (app.keyboard[SDL_SCANCODE_DOWN])
	{
		player.dy = PLAYER_SPEED;
	}

	if (app.keyboard[SDL_SCANCODE_LEFT])
	{
		player.dx = -PLAYER_SPEED;
	}

	if (app.keyboard[SDL_SCANCODE_RIGHT])
	{
		player.dx = PLAYER_SPEED;
	}

	if (player.reload == 0)
	{
		fireBullet();
	}

	player.x += player.dx;
	player.y += player.dy;
    if(player.x<0)
    {
        player.x=0;
    }
    if(player.x>1180)
    {
        player.x=1180;
    }
    if(player.y<0)
    {
        player.y=0;
    }
    if(player.y>597)
    {
        player.y=597;
    }
}
#endif
