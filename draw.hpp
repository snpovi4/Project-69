#pragma once
#ifndef draw_hpp
#define draw_hpp 
#include <SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_timer.h>
#include <bits/stdc++.h>
using namespace std;

void prepareScene(void)
{
	SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);
	SDL_RenderClear(app.renderer);
}

void presentScene(void)
{
	SDL_RenderPresent(app.renderer);
}

SDL_Texture *loadTexture(char *filename)
{
	SDL_Texture *texture;

	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

	texture = IMG_LoadTexture(app.renderer, filename);

	return texture;
}

void blit(SDL_Texture *texture, int x, int y)
{
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopy(app.renderer, texture, NULL, &dest);
}

void drawPlayer(void)
{
	blit(player.texture, player.x, player.y);
}
void drawBullet(void)
{
	for(auto tmp : bullet)
	{
		blit(tmp.texture, tmp.x, tmp.y);
	}
}
static void drawenemy(void)
{
	for (auto tmp : enemy)
	{
		blit(tmp.texture, tmp.x, tmp.y);
	}
	for (auto tmp : destroyed_enemy)
	{
		blit(tmp.texture, tmp.x, tmp.y);
	}
}

static void draw(void)
{
	drawPlayer();
	drawBullet();
	drawenemy();
}

#endif
