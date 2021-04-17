#include <SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_timer.h>
#include<bits/stdc++.h>
#include "defs.hpp"
#include "structure.hpp"
#include "init.hpp"
#include "Input.hpp"
#include "draw.hpp"
#include "movement.hpp"

using namespace std;


int main(int argc, char* argv[])
{
    
    memset(&app,0,sizeof(renderwindow));
    memset(&player,0,sizeof(Entity));
    initSDL();

	player.x = 590;
	player.y = 597;
    player.health=100;
	player.texture = loadTexture("ship2.png");
    bullet.texture = loadTexture("bullet_level_1.png");
    while (1)
	{
		prepareScene();
        
		doInput();

        if(bullet.health==0)
        {
            //add bullet audio
            bullet.x=player.x+35;
            bullet.y=player.y;
            bullet.dy=16;
            bullet.dx=0;
            bullet.health=1;
        }
        bullet.x+=bullet.dx;
        bullet.y-=bullet.dy;

        if(bullet.y<-50)
        {
            bullet.health=0;
        }
        blit(player.texture, player.x, player.y);
        if(bullet.health>0)
        {
            blit(bullet.texture,bullet.x,bullet.y);
        }
        
		presentScene();

		SDL_Delay(16);
	}
    return 0;
}

