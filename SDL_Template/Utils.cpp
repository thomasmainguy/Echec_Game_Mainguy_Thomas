#include <SDL_image.h>
#include "Utils.h"

Utils::Utils()
{
}

Utils::~Utils()
{
}

SDL_Surface* Utils::LoadSurface(std::string path)
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		return loadedSurface;
	}

	return nullptr;
}
