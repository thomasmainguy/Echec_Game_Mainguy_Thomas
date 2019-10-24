#pragma once
#include <SDL.h>
#include <string>

class Utils
{
public:
	Utils();
	~Utils();

	///<summary>load la surface </summary>
	static SDL_Surface* LoadSurface(std::string a_Path);
};

