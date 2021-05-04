#pragma once
#ifndef Stage_hpp
#define Stage_hpp 
#include <SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_timer.h>
#include <bits/stdc++.h>
#include "Collision.hpp"
using namespace std;

static void capFrameRate(long *then, float *remainder)
{
	long wait, frameTime;

	wait = 16 + *remainder;

	*remainder -= (int)*remainder;

	frameTime = SDL_GetTicks() - *then;

	wait -= frameTime;

	if (wait < 1)
	{
		wait = 1;
	}

	SDL_Delay(wait);

	*remainder += 0.667;

	*then = SDL_GetTicks();
}

bool bulletHitfighet(Entity *temp)
{
    for(int i=0;i<enemy.size();i++)
    {
        if (enemy[i].side != temp->side && collision(temp->x, temp->y, temp->w, temp->h, enemy[i].x, enemy[i].y, enemy[i].w, enemy[i].h))
        {
            enemy[i].health -= temp->health;
            temp->health = 0;
            return true;
        }
    }
    return false;
}
void initplayer(void)
{
    memset(&player,0,sizeof(Entity));
    player.texture = loadTexture("ship2.png");
    player.x = 590;
	player.y = 597;
    player.w=100;
    player.h=123;
    player.side=SIDE_PLAYER;
}

void initstage(void)
{
    initplayer();
    enemyspawntimer=0;
}
void doBullet(void)
{
    vector<int>pos;
    for(int i=0;i<bullet.size();i++)
    {
        bullet[i].x += bullet[i].dx;
		bullet[i].y += bullet[i].dy;
        if(bullet[i].y<0 || bulletHitfighet(&bullet[i]))
        {
            pos.push_back(i);
        }
    }
    sort(pos.rbegin(),pos.rend());
    for(int i=0;i<pos.size();i++)
    {
        bullet.erase(bullet.begin()+pos[i]);
    }
}

void doenemy(void)
{
    vector<int>pos;
    for(int i=0;i<enemy.size();i++)
    {
        enemy[i].x += enemy[i].dx;
		enemy[i].y += enemy[i].dy;
        if(enemy[i].y>720 || enemy[i].health<=0)
        {
            pos.push_back(i);
        }
    }
    sort(pos.rbegin(),pos.rend());
    for(int i=0;i<pos.size();i++)
    {   
        if(rand()%2==0){
            enemy[pos[i]].dx=10;
        }
        else{
            enemy[pos[i]].dx=-10;
        }
        enemy[pos[i]].dy=5;
        enemy[pos[i]].texture = loadTexture("efct.png");
        destroyed_enemy.push_back(enemy[pos[i]]);
        enemy.erase(enemy.begin()+pos[i]);
    }
    pos.clear();
    for(int i=0;i<destroyed_enemy.size();i++)
    {
        destroyed_enemy[i].x += destroyed_enemy[i].dx;
		destroyed_enemy[i].y += destroyed_enemy[i].dy;
        if(destroyed_enemy[i].y>720)
        {
            pos.push_back(i);
        }
    }
    sort(pos.rbegin(),pos.rend());
    for(int i=0;i<pos.size();i++)
    {   
        destroyed_enemy.erase(destroyed_enemy.begin()+pos[i]);
    }
}
#endif
