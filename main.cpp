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
#include "stage.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    memset(&app, 0, sizeof(App));
	memset(&player, 0, sizeof(Entity));
    memset(&bullet,0,sizeof(Entity));

	initSDL();


	player.texture = loadTexture("ship2.png");
    
	player.x = 590;
	player.y = 597;

	while (1)
	{
		prepareScene();

		doInput();

		movePlayer();

		doBullet();

        draw();
        
		presentScene();

		SDL_Delay(16);
	}
    return 0;
}

