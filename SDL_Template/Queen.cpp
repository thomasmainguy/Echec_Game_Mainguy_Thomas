#include "Queen.h"
#include "Utils.h"



Queen::Queen(bool a_White)
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

	//NorthEst
	posMoves.push_back(vector<std::pair<int, int>>());
	for (int k = 1; k < 9; k++)
	{
		posMoves[4].push_back(std::make_pair(k, -k));
	}

	//NorthWest
	posMoves.push_back(vector<std::pair<int, int>>());
	for (int k = 1; k < 9; k++)
	{
		posMoves[5].push_back(std::make_pair(-k, -k));
	}

	//SouthEst
	posMoves.push_back(vector<std::pair<int, int>>());
	for (int k = 1; k < 9; k++)
	{
		posMoves[6].push_back(std::make_pair(k, k));
	}

	//SouthWEst
	posMoves.push_back(vector<std::pair<int, int>>());
	for (int k = 1; k < 9; k++)
	{
		posMoves[7].push_back(std::make_pair(-k, k));
	}


	m_White = a_White;
	if (m_White)
	{
		m_Texture = Utils::LoadSurface("images/queen_white.png");
	}
	else
	{
		m_Texture = Utils::LoadSurface("images/queen_black.png");
	}
}


Queen::~Queen()
{
}
