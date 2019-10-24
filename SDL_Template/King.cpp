#include "King.h"
#include "Utils.h"


King::King(bool a_White)
	: Piece(a_White)
{
	//North
	posMoves.push_back(vector<std::pair<int, int>>());
	posMoves[0].push_back(std::make_pair(0, -1));
	//South
	posMoves.push_back(vector<std::pair<int, int>>());
	posMoves[1].push_back(std::make_pair(0, 1));
	//Est
	posMoves.push_back(vector<std::pair<int, int>>());
	posMoves[2].push_back(std::make_pair(1, 0));
	//West
	posMoves.push_back(vector<std::pair<int, int>>());
	posMoves[3].push_back(std::make_pair(-1, 0));
	//NorthEst
	posMoves.push_back(vector<std::pair<int, int>>());
	posMoves[4].push_back(std::make_pair(1, -1));
	//NorthWest
	posMoves.push_back(vector<std::pair<int, int>>());
	posMoves[5].push_back(std::make_pair(-1, -1));
	//SouthEst
	posMoves.push_back(vector<std::pair<int, int>>());
	posMoves[6].push_back(std::make_pair(1, 1));
	//SouthWest
	posMoves.push_back(vector<std::pair<int, int>>());
	posMoves[7].push_back(std::make_pair(-1, 1));

	m_White = a_White;
	if (m_White)
	{
		m_Texture = Utils::LoadSurface("images/king_white.png");
	}
	else
	{
		m_Texture = Utils::LoadSurface("images/king_black.png");
	}
}


King::~King()
{
}
