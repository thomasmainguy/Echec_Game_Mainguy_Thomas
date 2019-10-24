#include "Piece.h"
#include "Tile.h"



Piece::Piece(bool a_White)
	: m_White(a_White)
{

}


Piece::~Piece()
{
}

void Piece::Draw(SDL_Surface * a_ScreenSurface, SDL_Rect & a_Rect)
{
	SDL_BlitSurface(m_Texture, nullptr, a_ScreenSurface, &a_Rect);
}

vector<vector<std::pair<int, int>>> Piece::GetPosMoves()
{
	return posMoves;
}

bool Piece::GetColor()
{
	return m_White;
}


