//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "Game.h"

int main(int argc, char* args[])
{
	Game* game = new Game();

	while (true)
	{
		game->Draw();
		game->Update();
	}

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}