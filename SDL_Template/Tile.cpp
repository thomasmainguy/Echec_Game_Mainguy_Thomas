#include "Tile.h"
#include "Piece.h"
#include "Utils.h"
#include <iostream>

Tile::Tile(const int& x, const int& y, Piece* a_Piece)
	: m_IsEmpty(false)
	, m_SurfaceOfTile(nullptr)
	, m_CurrentPiece(nullptr)
{
	m_Rect.x = x;
	m_Rect.y = y;
	m_Rect.w = 100;
	m_Rect.h = 100;

	m_CurrentPiece = a_Piece;
	m_SurfaceOfTile = Utils::LoadSurface("images/PosTiles.png");
}

Tile::~Tile()
{
	//deleting piece
	if (m_CurrentPiece != nullptr)
	{
		delete m_CurrentPiece;
		m_CurrentPiece = nullptr;
	}

	//deleting the surface of the tile
	if (m_SurfaceOfTile != nullptr)
	{
		SDL_FreeSurface(m_SurfaceOfTile);
		m_SurfaceOfTile = nullptr;
	}

}

void Tile::Draw(SDL_Surface* a_ScreenSurface)
{
	if (m_IsEmpty)
	{
		SDL_BlitSurface(m_SurfaceOfTile, nullptr, a_ScreenSurface, &m_Rect);
	}


	//if the tile have a piece draw it, otherwise, skip.
	if (m_CurrentPiece != nullptr)
	{
		m_CurrentPiece->Draw(a_ScreenSurface, m_Rect);
	}


}


Piece * Tile::GetTileType()
{
	return m_CurrentPiece;
}

void Tile::MoveRect()
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	m_Rect.x = x - 50;
	m_Rect.y = y - 50;
}

void Tile::MoveRect(int LastX, int LastY)
{
	m_Rect.x = LastX;
	m_Rect.y = LastY;
}

//for the behavior
void Tile::SetPieceTo(Piece * a_NewPiece)
{
	m_CurrentPiece = a_NewPiece;
}

//pour remettre le tile du debut a 0
void Tile::ResetTile()
{
	//need to make a delte and not a nullptr
	if (m_CurrentPiece != nullptr)
	{
		m_CurrentPiece = nullptr;
	}

}

bool Tile::IsTileEmpty()
{
	if (m_CurrentPiece == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Tile::SetBoolGreen(bool a_Bool)
{
	m_IsEmpty = a_Bool;
}
