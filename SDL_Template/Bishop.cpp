#include "Bishop.h"
#include "Utils.h"



Bishop::Bishop(bool a_White)
	: Piece(a_White)
{
	//others
	posMoves.push_back(vector<std::pair<int, int>>());
	posMoves.push_back(vector<std::pair<int, int>>());
	posMoves.push_back(vector<std::pair<int, int>>());
	posMoves.push_back(vector<std::pair<int, int>>());

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

	//SouthWest
	posMoves.push_back(vector<std::pair<int, int>>());
	for (int k = 1; k < 9; k++)
	{
		posMoves[7].push_back(std::make_pair(-k, k));
	}



	m_White = a_White;
	if (m_White)
	{
		m_Texture = Utils::LoadSurface("images/bishop_white.png");
	}
	else
	{
		m_Texture = Utils::LoadSurface("images/bishop_black.png");
	}
}


Bishop::~Bishop()
{
}
