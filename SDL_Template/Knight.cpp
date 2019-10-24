#include "Knight.h"
#include "Utils.h"


Knight::Knight(bool a_White)
	: Piece(a_White)
{
	posMoves.push_back(vector<std::pair<int, int>>());
	posMoves[0].push_back(std::make_pair(2, -1));

	posMoves.push_back(vector<std::pair<int, int>>());
	posMoves[1].push_back(std::make_pair(-2, -1));

	posMoves.push_back(vector<std::pair<int, int>>());
	posMoves[2].push_back(std::make_pair(-1, 2));

	posMoves.push_back(vector<std::pair<int, int>>());
	posMoves[3].push_back(std::make_pair(2, 1));





	//NorthEst
	posMoves.push_back(vector<std::pair<int, int>>());
	posMoves[4].push_back(std::make_pair(1, -2));

	//NorthWest
	posMoves.push_back(vector<std::pair<int, int>>());
	posMoves[5].push_back(std::make_pair(-1, -2));


	//SouthEst
	posMoves.push_back(vector<std::pair<int, int>>());
	posMoves[6].push_back(std::make_pair(1, 2));


	//SouthWest
	posMoves.push_back(vector<std::pair<int, int>>());
	posMoves[7].push_back(std::make_pair(-2, 1));



	m_White = a_White;
	if (m_White)
	{
		m_Texture = Utils::LoadSurface("images/knight_white.png");
	}
	else
	{
		m_Texture = Utils::LoadSurface("images/knight_black.png");
	}
}


Knight::~Knight()
{
}
