#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

// forward declaration
class Board;

class Game
{
public:
	Game();
	~Game();

	///<summary>Cree la SDL(window)</summary>
	void InitSDL();
	///<summary>Creer un new board </summary>
	void InitGame();
	///<summary>Appelle du event de board</summary>
	void handleEvent(SDL_Event &e);
	///<summary>draw le board en updatant la window et le rect de la screen surface<summary>
	void Draw();
	///<summary>permet l'update de l'event </summary>
	void Update();

private:

	//Screen dimension constants
	///<param name = "SCREEN_WIDTH">Constante de la screen width</param>
	const int SCREEN_WIDTH = 800;

	///<param name = "SCREEN_HEIGHT">Constante de la screen height</param>
	const int SCREEN_HEIGHT = 800;

	///<param name = "m_Window">Pointeur sur la Window</param>
	SDL_Window* m_Window;

	///<param name = "m_ScreenSurface">Pointeur sur la surface de la screen</param>
	SDL_Surface* m_ScreenSurface;

	///<param name = "m_Board">Pointeur sur le board(pour le init dans la game)</param>
	Board* m_Board;
};