#pragma once
#ifndef Stage_hpp
#define Stage_hpp 
#include <SDL2/SDL.h>
#include<SDL2/SDL_timer.h>
#include <bits/stdc++.h>

using namespace std;

void doBullet(void)
{
    vector<int>pos;
    for(int i=0;i<bullet.size();i++)
    {
        bullet[i].x += bullet[i].dx;
		bullet[i].y += bullet[i].dy;
        if(bullet[i].y<0)
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

#endif
