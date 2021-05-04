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
#include "Collision.hpp"
using namespace std;

int main(int argc, char* argv[])
{
	//double then,remainder;

    memset(&app, 0, sizeof(App));

	initSDL();

	initstage();

	//then = SDL_GetTicks();

	//remainder = 0;

	while (1)
	{
		prepareScene();

		doInput();

		movePlayer();

		doenemy();

		doBullet();

		spawnenemy();

        draw();
        
		presentScene();

		//capFrameRate(&then, &remainder);
		SDL_Delay(16);
	}
    return 0;
}

