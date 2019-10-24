#pragma once
#include <SDL.h>
#include <vector>
#include <utility>

using std::vector;

class Piece
{
public:
	Piece(bool a_White);
	virtual ~Piece();

	void Draw(SDL_Surface* a_ScreenSurface, SDL_Rect& a_Rect);
	vector<vector<std::pair <int, int>>> GetPosMoves();
	bool GetColor();

protected:
	SDL_Surface* m_Texture;
	bool m_White;
	vector<vector< std::pair <int, int>>> posMoves;


};


