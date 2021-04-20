#pragma once
#ifndef movement_hpp
#define movement_hpp 
#include <SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_timer.h>
#include <bits/stdc++.h>
#include "draw.hpp"
using namespace std;

static void spawnenemy(void)
{
    if(--enemyspawntimer<=0)
    {
        Entity temp_enemy;
        temp_enemy.side=SIDE_ALIEN;
        temp_enemy.health=1;
        temp_enemy.w=80;
        temp_enemy.h=77;
        temp_enemy.y=0;
        temp_enemy.x= rand() % SCREEN_HEIGHT;
        temp_enemy.texture = loadTexture("enemy_ships_1.png");
        //SDL_QueryTexture(temp_enemy.texture, NULL, NULL, &temp_enemy.x, temp_enemy.y);
        temp_enemy.dy = (2 + (rand() % 4));
        temp_enemy.dx = 0;
		enemyspawntimer = 100 + (rand() % 60);
        enemy.push_back(temp_enemy);
    }
}

static void fireBullet(void)
{
    Entity temp_bullet;
    memset(&temp_bullet,0,sizeof(Entity));
    temp_bullet.side=SIDE_PLAYER;
    temp_bullet.x = player.x+35;
    temp_bullet.y = player.y;
    temp_bullet.w=30;
    temp_bullet.h=53;
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
