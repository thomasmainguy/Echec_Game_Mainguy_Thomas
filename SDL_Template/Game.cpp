#include "Game.h"
#include "Utils.h"
#include "Board.h"
#include <iostream>

Game::Game()
	: m_Window(nullptr)
	, m_ScreenSurface(nullptr)
	, m_Board(nullptr)
{
	// Init SDL library.
	InitSDL();

	// Init the game
	InitGame();

	//Fill the surface white
	SDL_FillRect(m_ScreenSurface, NULL, SDL_MapRGB(m_ScreenSurface->format, 0xFF, 0xFF, 0xFF));
}


Game::~Game()
{
	//Destroy window
	SDL_DestroyWindow(m_Window);

	if (m_Board != nullptr)
	{
		delete m_Board;
		m_Board = nullptr;
	}

	if (m_ScreenSurface != nullptr)
	{
		delete m_ScreenSurface;
		m_ScreenSurface = nullptr;
	}
}

void Game::InitSDL()
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		m_Window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (m_Window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
			}
			else
			{
				//Get window surface
				m_ScreenSurface = SDL_GetWindowSurface(m_Window);

				// Initialize done.
			}
		}
	}
}

void Game::InitGame()
{
	// Init all objects related to the game
	m_Board = new Board();
}

void Game::Update()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	handleEvent(event);
}

void Game::handleEvent(SDL_Event &e)
{
	m_Board->handleEvent(&e);
}

void Game::Draw()
{
	//Fill the surface white
	SDL_FillRect(m_ScreenSurface, NULL, SDL_MapRGB(m_ScreenSurface->format, 0xFF, 0xFF, 0xFF));

	m_Board->Draw(m_ScreenSurface);


	//Update the surface - Alway at the end!
	SDL_UpdateWindowSurface(m_Window);
}