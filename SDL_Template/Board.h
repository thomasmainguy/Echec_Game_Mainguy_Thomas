#pragma once
#include <vector>
#include <SDL.h>


// forward declaration
class Tile;
class Piece;

using std::vector;

enum Direction
{
	North,
	South,
	Est,
	West,
	NorthEst,
	NorthWest,
	SouthEst,
	SouthWest,
	Count
};

class Board
{
public:
	Board();
	~Board();

	///<summary>Set up le Event de SDL</summary>
	void handleEvent(SDL_Event* e);
	///<summary>Draw la surface necessaire</summary>
	void Draw(SDL_Surface* a_ScreenSurface);

private:
	///<summary>Set le tour au int aproprie 1 pour les blancs 0 pour les noirs</summary>
	void SetTurn(int a_Int);

	///<param name = "m_Turn"> donne le tour que le jeu est rendu soit 1 ou 0</param>
	int m_Turn;

	///<param name = "m_Highlited"> donne si les piece sont highlited ou pas pour les dessiner ou pas</param>
	bool m_Highlited;

	///<param name = "m_TilesWidth"> constante de la largeur d'une tile</param>
	const int m_TilesWidth = 100;

	///<param name = "m_TilesHeight"> constante de la hauteur d'une tile</param>
	const int m_TilesHeight = 100;

	///<param name = "m_LastPosX"> sert a set a la derniere position qu'on a pris la tile pour les cols</param>
	int m_LastPosX;

	///<param name = "m_LastPosY"> sert a set a la derniere position qu'on a pris la tile pour les rows</param>
	int m_LastPosY;

	///<param name = "m_TileInMove"> pointeur qui signifie la tile prise(qui est en mouvement)</param>
	Tile* m_TileInMove;

	///<param name = "m_TilesPos">Le vecteur de tile possible (ou le mouvement est possible)</param>
	vector<Tile*> m_TilesPos;

	///<param name = "m_Tiles">Le vecteur de tout les tiles du board</param>
	vector<vector<Tile*>> m_Tiles;

	///<param name = "m_BoardSurface">Pointeur sur la surface du board</param>
	SDL_Surface* m_BoardSurface;

	///<param name = "m_GreenTile">Pointeur sur la surface d'une tile possible(green alpha low)</param>
	SDL_Surface* m_GreenTile;
};

