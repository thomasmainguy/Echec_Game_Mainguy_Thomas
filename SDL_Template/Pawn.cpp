#include "Pawn.h"
#include "Utils.h"



Pawn::Pawn(bool a_White)
	: Piece(a_White)
	, m_FirstMove(true)
{
	if (m_White)
	{
		//North
		posMoves.push_back(vector<std::pair<int, int>>());
		posMoves[0].push_back(std::make_pair(0, -1));
		posMoves[0].push_back(std::make_pair(0, -2));

		posMoves.push_back(vector<std::pair<int, int>>());
		posMoves.push_back(vector<std::pair<int, int>>());
		posMoves.push_back(vector<std::pair<int, int>>());

		//NorthEst
		posMoves.push_back(vector<std::pair<int, int>>());
		posMoves[4].push_back(std::make_pair(1, -1));

		//NorthWest
		posMoves.push_back(vector<std::pair<int, int>>());
		posMoves[5].push_back(std::make_pair(-1, -1));

		posMoves.push_back(vector<std::pair<int, int>>());
		posMoves.push_back(vector<std::pair<int, int>>());



	}
	else
	{
		posMoves.push_back(vector<std::pair<int, int>>());

		//South
		posMoves.push_back(vector<std::pair<int, int>>());
		posMoves[1].push_back(std::make_pair(0, 1));
		posMoves[1].push_back(std::make_pair(0, 2));

		posMoves.push_back(vector<std::pair<int, int>>());
		posMoves.push_back(vector<std::pair<int, int>>());
		posMoves.push_back(vector<std::pair<int, int>>());
		posMoves.push_back(vector<std::pair<int, int>>());

		//SouthEst
		posMoves.push_back(vector<std::pair<int, int>>());
		posMoves[6].push_back(std::make_pair(1, 1));

		//SouthWest
		posMoves.push_back(vector<std::pair<int, int>>());
		posMoves[7].push_back(std::make_pair(-1, 1));
	}




	if (m_White)
	{
		m_Texture = Utils::LoadSurface("images/pawn_white.png"); // pour loader la bonne texture dans le folder
	}
	else
	{
		m_Texture = Utils::LoadSurface("images/pawn_black.png"); // pour loader la bonne texture dans le folder
	}
}

Pawn::~Pawn()
{
}


