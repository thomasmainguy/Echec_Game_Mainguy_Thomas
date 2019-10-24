#include "Board.h"
#include "Utils.h"
#include "Tile.h"
#include "Pawn.h"
#include "Queen.h"
#include "King.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include <iostream>


Board::Board()
	: m_Turn(1)
	, m_Highlited(false)
	, m_TileInMove(nullptr)
	, m_LastPosX()
	, m_LastPosY()
{
	m_BoardSurface = Utils::LoadSurface("images/chessboard.png");

	for (int i = 0; i < 8; i++)
	{
		// Populate the first dimension of the vector<vector<Tiles*>> 
		// with an empty vector of Tile*
		m_Tiles.push_back(vector<Tile*>());
		for (int j = 0; j < 8; j++)
		{
			// Populate the second dimension of the vector<vector<Tile*>>
			// with fresh new tile
			if (j == 1)
			{
				m_Tiles[i].push_back(new Tile(i * m_TilesWidth, j * 100, new Pawn(true)));
			}
			else if ((i == 0 || i == 7) && j == 0)
			{
				m_Tiles[i].push_back(new Tile(i * m_TilesWidth, j * m_TilesHeight, new Rook(true)));
			}
			else if ((i == 1 || i == 6) && j == 0)
			{
				m_Tiles[i].push_back(new Tile(i * m_TilesWidth, j * m_TilesHeight, new Knight(true)));
			}
			else if ((i == 2 || i == 5) && j == 0)
			{
				m_Tiles[i].push_back(new Tile(i * m_TilesWidth, j * m_TilesHeight, new Bishop(true)));
			}
			else if (i == 4 && j == 0)
			{
				m_Tiles[i].push_back(new Tile(i * m_TilesWidth, j * m_TilesHeight, new Queen(true)));
			}
			else if (i == 3 && j == 0)
			{
				m_Tiles[i].push_back(new Tile(i * m_TilesWidth, j * m_TilesHeight, new King(true)));
			}
			else if ((i == 0 || i == 7) && j == 7)
			{
				m_Tiles[i].push_back(new Tile(i * m_TilesWidth, j * m_TilesHeight, new Rook(false)));
			}
			else if ((i == 1 || i == 6) && j == 7)
			{
				m_Tiles[i].push_back(new Tile(i * m_TilesWidth, j * m_TilesHeight, new Knight(false)));
			}
			else if ((i == 2 || i == 5) && j == 7)
			{
				m_Tiles[i].push_back(new Tile(i * m_TilesWidth, j * m_TilesHeight, new Bishop(false)));
			}
			else if (i == 4 && j == 7)
			{
				m_Tiles[i].push_back(new Tile(i * m_TilesWidth, j * m_TilesHeight, new Queen(false)));
			}
			else if (i == 3 && j == 7)
			{
				m_Tiles[i].push_back(new Tile(i * m_TilesWidth, j * m_TilesHeight, new King(false)));
			}
			else if (j == 6)
			{
				m_Tiles[i].push_back(new Tile(i * m_TilesWidth, j * m_TilesHeight, new Pawn(false)));
			}
			else
			{
				m_Tiles[i].push_back(new Tile(i * m_TilesWidth, j * m_TilesHeight, nullptr));
			}
		}
	}
}

Board::~Board()
{
	//delete les tiles du board
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			delete m_Tiles[i][j];
		}
	}

	//deleting board surface 
	if (m_BoardSurface != nullptr)
	{
		SDL_FreeSurface(m_BoardSurface);
		m_BoardSurface = nullptr;
	}

	//precaution car la variable est toujours set a null dans les fonctions
	if (m_GreenTile != nullptr)
	{
		SDL_FreeSurface(m_GreenTile);;
		m_GreenTile = nullptr;
	}

	//precaution car la variable est toujours set a null dans les fonctions
	if (m_TileInMove != nullptr)
	{
		delete m_TileInMove;
		m_TileInMove = nullptr;
	}
}


void Board::handleEvent(SDL_Event* e)
{

	if (m_TileInMove != nullptr && e->type == SDL_MOUSEMOTION)
	{
		m_TileInMove->MoveRect();
	}

	if (e->type == SDL_MOUSEBUTTONDOWN)
	{
		m_Highlited = true;
		int x, y;
		SDL_GetMouseState(&x, &y);

		int j = (y / m_TilesWidth);
		int i = (x / m_TilesHeight);

		m_LastPosX = i;
		m_LastPosY = j;
		m_TileInMove = m_Tiles[i][j];

		Pawn*  m_Pawn = dynamic_cast<Pawn*>(m_TileInMove->GetTileType());

		//set turn for white
		if (m_Turn == 1)
		{
			//if he is a pawn
			if (m_Pawn != nullptr)
			{
#pragma region //MovePawnWhite



				//first move white
				if (m_Pawn->FirstMove() == true && m_Pawn->GetColor() == true)
				{
					if (m_Tiles[0 + i][1 + j]->GetTileType() == nullptr)
					{
						m_TilesPos.push_back(m_Tiles[0 + i][1 + j]);
					}

					if (m_Tiles[0 + i][1 + j]->GetTileType() == nullptr && m_Tiles[0 + i][2 + j]->GetTileType() == nullptr)
					{
						m_TilesPos.push_back(m_Tiles[0 + i][2 + j]);
					}

					//check diagonals South Est
					if ((1 + i >= 0 && 1 + i < 8 && 1 + j < 8) &&
						m_Tiles[1 + i][1 + j] != nullptr && m_Tiles[1 + i][1 + j]->GetTileType() != nullptr)
					{
						if (m_Tiles[1 + i][1 + j] != nullptr && m_Tiles[1 + i][1 + j]->GetTileType()->GetColor() == false)
						{
							m_TilesPos.push_back(m_Tiles[1 + i][1 + j]);
						}
					}

					//check diagonals South West
					if ((-1 + i >= 0 && -1 + i <= 8 && 1 + j < 8) &&
						m_Tiles[-1 + i][1 + j] != nullptr && m_Tiles[-1 + i][1 + j]->GetTileType() != nullptr)
					{
						if (m_Tiles[-1 + i][1 + j] != nullptr && m_Tiles[-1 + i][1 + j]->GetTileType()->GetColor() == false)
						{
							m_TilesPos.push_back(m_Tiles[-1 + i][1 + j]);
						}
					}
				}

				//for white second move
				if (m_Pawn->FirstMove() == false && m_Pawn->GetColor() == true)
				{

					//check tile in front if empty
					if (0 + i < 8 && 1 + j < 8 && m_Tiles[0 + i][1 + j]->GetTileType() == nullptr)
					{
						m_TilesPos.push_back(m_Tiles[0 + i][1 + j]);
					}


					//check diagonals South Est
					if ((1 + i > 0 && 1 + i < 8 && 1 + j < 8) &&
						m_Tiles[1 + i][1 + j] != nullptr && m_Tiles[1 + i][1 + j]->GetTileType() != nullptr)
					{
						if (m_Tiles[1 + i][1 + j] != nullptr && m_Tiles[1 + i][1 + j]->GetTileType()->GetColor() == false)
						{
							m_TilesPos.push_back(m_Tiles[1 + i][1 + j]);
						}
					}

					//check diagonals South West
					if ((-1 + i > -1 && -1 + i < 8 && 1 + j < 8) &&
						m_Tiles[-1 + i][1 + j] != nullptr && m_Tiles[-1 + i][1 + j]->GetTileType() != nullptr)
					{
						if (m_Tiles[-1 + i][1 + j]->GetTileType()->GetColor() == false)
						{
							m_TilesPos.push_back(m_Tiles[-1 + i][1 + j]);
						}
					}
				}
#pragma endregion
			}

			//if its other piece
			if (m_Tiles[i][j] != nullptr && m_Pawn == nullptr)
			{
#pragma region	//OtherMvtWhite

				if (m_TileInMove->GetTileType() != nullptr && m_TileInMove->GetTileType()->GetColor() == true)
				{
					vector<vector<std::pair<int, int>>> posMoves = m_TileInMove->GetTileType()->GetPosMoves();

					//Directions = k
					for (int k = 0; k < Direction::Count; k++)
					{
						//Nb of pairs
						for (int x = 0; x < posMoves[k].size(); x++)
						{
							//setting the pair of position in the vector of position to the col and row in the board
							int PosRow = posMoves[k][x].first + i;
							int PosCol = posMoves[k][x].second + j;

							if (PosRow >= 0 && PosRow < 8 && PosCol >= 0 && PosCol < 8)
							{

								int q = 0;
								if (((m_Tiles[PosRow][PosCol]->GetTileType() != nullptr &&
									m_Tiles[PosRow][PosCol]->GetTileType()->GetColor() != m_TileInMove->GetTileType()->GetColor())) && q == 0)
								{
									//populate the vector of possible moves and q++ is for if its a opposite color 
									q++;
									m_TilesPos.push_back(m_Tiles[PosRow][PosCol]);
								}
								if (m_Tiles[PosRow][PosCol]->GetTileType() == nullptr)
								{
									//populate the vector of possible moves
									m_TilesPos.push_back(m_Tiles[PosRow][PosCol]);
								}
								else
								{
									break;
								}

							}
							else
							{
								break;
							}
						}
					}
				}
#pragma endregion
			}
		}

		//set turn for black
		if (m_Turn == 0)
		{
			//if he is a pawn
			if (m_Pawn != nullptr)
			{
#pragma region //MovePawnBlack

				//first move black
				if (m_Pawn->FirstMove() == true && m_Pawn->GetColor() == false && m_Tiles[0 + i][-1 + j]->GetTileType() == nullptr)
				{
					if (m_Tiles[0 + i][-1 + j]->GetTileType() == nullptr)
					{
						m_TilesPos.push_back(m_Tiles[0 + i][-1 + j]);
					}

					if (m_Tiles[0 + i][-1 + j]->GetTileType() == nullptr && m_Tiles[0 + i][-2 + j]->GetTileType() == nullptr)
					{
						m_TilesPos.push_back(m_Tiles[0 + i][-2 + j]);
					}
					//check diagonals North Est
					if ((1 + i > 0 && 1 + i < 8 && -1 + j > 0) &&
						m_Tiles[1 + i][-1 + j] != nullptr  && m_Tiles[1 + i][-1 + j]->GetTileType() != nullptr)
					{
						if (m_Tiles[1 + i][-1 + j]->GetTileType()->GetColor() == true)
						{
							m_TilesPos.push_back(m_Tiles[1 + i][-1 + j]);
						}
					}

					//check diagonals South West
					if ((-1 + i > 0 && -1 + i < 8 && -1 + j > 0) &&
						m_Tiles[-1 + i][-1 + j] != nullptr && m_Tiles[-1 + i][-1 + j]->GetTileType() != nullptr)
					{
						if (m_Tiles[-1 + i][-1 + j]->GetTileType()->GetColor() == true)
						{
							m_TilesPos.push_back(m_Tiles[-1 + i][-1 + j]);
						}
					}
				}

				//for black second move
				if (m_Pawn->FirstMove() == false && m_Pawn->GetColor() == false)
				{
					//check tile in front if empty
					if (-1 + j >= 0 && m_Tiles[0 + i][-1 + j]->GetTileType() == nullptr)
					{
						m_TilesPos.push_back(m_Tiles[0 + i][-1 + j]);
					}


					//check diagonals North Est
					if ((1 + i >= 0 && 1 + i < 8 && -1 + j >= 0) &&
						m_Tiles[1 + i][-1 + j] != nullptr && m_Tiles[1 + i][-1 + j]->GetTileType() != nullptr)
					{
						if (m_Tiles[1 + i][-1 + j] != nullptr && m_Tiles[1 + i][-1 + j]->GetTileType()->GetColor() == true)
						{
							m_TilesPos.push_back(m_Tiles[1 + i][-1 + j]);
						}
					}

					//check diagonals North West 
					if ((-1 + i >= 0 && -1 + i < 8 && -1 + j >= 0) &&
						m_Tiles[-1 + i][-1 + j] != nullptr && m_Tiles[-1 + i][-1 + j]->GetTileType() != nullptr)
					{
						if (m_Tiles[-1 + i][-1 + j]->GetTileType()->GetColor() == true)
						{
							m_TilesPos.push_back(m_Tiles[-1 + i][-1 + j]);
						}
					}
				}
#pragma endregion
			}

			//if its other piece
			if (m_Tiles[i][j] != nullptr && m_Pawn == nullptr)
			{
#pragma region	//OtherMvtBlack

				if (m_TileInMove->GetTileType() != nullptr && m_TileInMove->GetTileType()->GetColor() == false)
				{
					vector<vector<std::pair<int, int>>> posMoves = m_TileInMove->GetTileType()->GetPosMoves();

					//Directions = k
					for (int k = 0; k < Direction::Count; k++)
					{
						//Nb of pairs
						for (int x = 0; x < posMoves[k].size(); x++)
						{
							//setting the pair of position in the vector of position to the col and row in the board
							int PosRow = posMoves[k][x].first + i;
							int PosCol = posMoves[k][x].second + j;

							if (PosRow >= 0 && PosRow < 8 && PosCol >= 0 && PosCol < 8)
							{

								int q = 0;
								if (((m_Tiles[PosRow][PosCol]->GetTileType() != nullptr &&
									m_Tiles[PosRow][PosCol]->GetTileType()->GetColor() != m_TileInMove->GetTileType()->GetColor())) && q == 0)
								{
									//populate the vector of possible moves and q++ is for if its a opposite color 
									q++;
									m_TilesPos.push_back(m_Tiles[PosRow][PosCol]);
								}
								if (m_Tiles[PosRow][PosCol]->GetTileType() == nullptr)
								{
									//populate the vector of possible moves
									m_TilesPos.push_back(m_Tiles[PosRow][PosCol]);
								}
								else
								{
									break;
								}

							}
							else
							{
								break;
							}
						}
					}
				}
#pragma endregion
			}
		}

		//setting possibles tiles to green
		for (int k = 0; k < m_TilesPos.size(); k++)
		{
			m_TilesPos[k]->SetBoolGreen(true);
		}
	}


	if (e->type == SDL_MOUSEBUTTONUP)
	{
		//getting the pos of the mouse (col and row)
		m_Highlited = false;
		int x, y;
		SDL_GetMouseState(&x, &y);
		int j = (y / m_TilesWidth);
		int i = (x / m_TilesHeight);

		Pawn* m_Pawn = dynamic_cast<Pawn*>(m_TileInMove->GetTileType());

		//Set the current tile of the pawn to the good position 
		//and the good piece if his on the other side of the chess board


		if (m_Tiles[i][j] != nullptr && m_Pawn != nullptr)
		{

//Set the pawn to whatever you want worked for a while but now i need to focus on the principal things in the tp lel :P
#pragma region //Promotion


			/*for (int k = 0; k < 8; k++)
			{
				for (int x = 0; x < m_TilesPos.size(); x++)
				{
					if (m_Tiles[k][0] == m_TilesPos[x] && m_TileInMove->GetTileType()->GetColor() == false)
					{
						int Q;
						std::cout << "Pick youre figther! 1 = Queen; 2 = Knight; 3 = Rook" << std::endl;
						std::cin >> Q;
						if (Q == 1)
						{
							delete(m_TileInMove->GetTileType());
							m_TileInMove->SetPieceTo(new Queen(false));
						}
						else if (Q == 2)
						{
							delete(m_TileInMove->GetTileType());
							m_TileInMove->SetPieceTo(new Knight(false));
						}
						else if (Q == 3)
						{
							delete(m_TileInMove->GetTileType());
							m_TileInMove->SetPieceTo(new Rook(false));
						}
						else
						{
							std::cout << "Wrong choice!"<< std::endl;
						}
					}

					//Set the pawn to whatever you want for white
					if (m_Tiles[k][7] == m_TilesPos[x] && m_TileInMove->GetTileType()->GetColor() == false)
					{
						int Q;
						std::cout << "Pick youre figther! 1 = Queen; 2 = Knight; 3 = Rook" << std::endl;
						std::cin >> Q;
						if (Q == 1)
						{
							delete(m_TileInMove->GetTileType());
							m_TileInMove->SetPieceTo(new Queen(true));
						}
						else if (Q == 2)
						{
							delete(m_TileInMove->GetTileType());
							m_TileInMove->SetPieceTo(new Knight(true));
						}
						else if (Q == 3)
						{
							delete(m_TileInMove->GetTileType());
							m_TileInMove->SetPieceTo(new Rook(true));
						}
						else
						{
							std::cout << "Wrong choice!" << std::endl;
						}
					}
				}
			}*/
#pragma endregion

#pragma region //SetUpPawn
			for (int k = 0; k < m_TilesPos.size(); k++)
			{
				if (m_Tiles[i][j] == m_TilesPos[k] && m_Pawn->FirstMove() == true)
				{
					m_Tiles[i][j]->SetPieceTo(m_TileInMove->GetTileType());
					m_TileInMove->ResetTile();
					m_Pawn->SetBoolMove(false);
					if (m_Pawn->GetColor() == false)
					{
						SetTurn(1);
					}
					if (m_Pawn->GetColor() == true)
					{
						SetTurn(0);
					}
				}
				else if (m_Tiles[i][j] == m_TilesPos[k] && m_Pawn->FirstMove() == false)
				{
					m_Tiles[i][j]->SetPieceTo(m_TileInMove->GetTileType());
					m_TileInMove->ResetTile();
					if (m_Pawn->GetColor() == false)
					{
						SetTurn(1);
					}
					if (m_Pawn->GetColor() == true)
					{
						SetTurn(0);
					}
				}
			}
			m_TileInMove->MoveRect(m_LastPosX * m_TilesHeight, m_LastPosY * m_TilesWidth);
		}
#pragma endregion

		//Set the current tile/piece to the good position and the good piece
#pragma region //SetUpOtherPieces

		//for piece that are white
		if (m_Pawn == nullptr && m_TileInMove->GetTileType() != nullptr && m_TileInMove->GetTileType()->GetColor() == true)
		{
			for (int k = 0; k < m_TilesPos.size(); k++)
			{
				if (m_Tiles[i][j] == m_TilesPos[k])
				{
					m_Tiles[i][j]->SetPieceTo(m_TileInMove->GetTileType());
					m_TileInMove->ResetTile();
					SetTurn(0);
					break;
				}
			}
			m_TileInMove->MoveRect(m_LastPosX * m_TilesHeight, m_LastPosY * m_TilesWidth);
		}

		//for pieces that are black
		if (m_Pawn == nullptr && m_TileInMove->GetTileType() != nullptr  && m_TileInMove->GetTileType()->GetColor() == false)
		{
			for (int k = 0; k < m_TilesPos.size(); k++)
			{
				if (m_Tiles[i][j] == m_TilesPos[k])
				{
					m_Tiles[i][j]->SetPieceTo(m_TileInMove->GetTileType());
					m_TileInMove->ResetTile();
					SetTurn(1);
					break;
				}
			}
			m_TileInMove->MoveRect(m_LastPosX * m_TilesHeight, m_LastPosY * m_TilesWidth);
		}
	
#pragma endregion

		//setting possible tiles back to normal
		for (int k = 0; k < m_TilesPos.size(); k++)
		{
			m_TilesPos[k]->SetBoolGreen(false);
		}

		//setting my vector to nullptr to optimize code (it was a tip from simon to do so)
		for (int k = 0; k < m_TilesPos.size(); k++)
		{
			m_TilesPos[k] = nullptr;
		}

		//clearing the vector of tiles
		m_TilesPos.clear();

		//reseting my Tile in move to nullptr
		m_TileInMove = nullptr;
	}
}

void Board::Draw(SDL_Surface* a_ScreenSurface)
{
	SDL_BlitSurface(m_BoardSurface, nullptr, a_ScreenSurface, nullptr);

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			m_Tiles[i][j]->Draw(a_ScreenSurface);
		}
	}

	if (m_TileInMove != nullptr)
	{
		m_TileInMove->Draw(a_ScreenSurface);
	}
}



void Board::SetTurn(int a_Int)
{
	m_Turn = a_Int;
}


