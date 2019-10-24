#include "Rook.h"
#include "Utils.h"


Rook::Rook(bool a_White)
	: Piece(a_White)
{
	//Haut
	posMoves.push_back(vector<std::pair<int, int>>());
	for (int k = 1; k < 9; k++)
	{
		posMoves[0].push_back(std::make_pair(0, -k));
	}

	//Bas
	posMoves.push_back(vector<std::pair<int, int>>());
	for (int k = 1; k < 9; k++)
	{
		posMoves[1].push_back(std::make_pair(0, k));
	}

	//Droite
	posMoves.push_back(vector<std::pair<int, int>>());
	for (int k = 1; k < 9; k++)
	{
		posMoves[2].push_back(std::make_pair(k, 0));
	}

	//Gauche
	posMoves.push_back(vector<std::pair<int, int>>());
	for (int k = 1; k < 9; k++)
	{
		posMoves[3].push_back(std::make_pair(-k, 0));
	}

	//others
	posMoves.push_back(vector<std::pair<int, int>>());
	posMoves.push_back(vector<std::pair<int, int>>());
	posMoves.push_back(vector<std::pair<int, int>>());
	posMoves.push_back(vector<std::pair<int, int>>());




	m_White = a_White;
	if (m_White)
	{
		m_Texture = Utils::LoadSurface("images/rook_white.png");
	}
	else
	{
		m_Texture = Utils::LoadSurface("images/rook_black.png");
	}
}


Rook::~Rook()
{
}

