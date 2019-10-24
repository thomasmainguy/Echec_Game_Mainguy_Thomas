#pragma once
#include <SDL.h>

// forward declaration
class Piece;

class Tile
{
public:
	//Pass nullptr as a_Piece for an empty tile
	Tile(const int& x, const int& y, Piece* a_Piece);
	~Tile();

	///<summary>Draw la tile selon la surface passer</summary>
	void Draw(SDL_Surface* a_ScreenSurface);
	///<summary>///<return>return la piece sur la tile</return></summary>
	Piece * GetTileType();
	///<summary>deplace le rect de la tile selon la sourris</summary>
	void MoveRect();
	///<summary>deplace le rect de la tile a la position passer(position initial de la tile)</summary>
	void MoveRect(int OldX, int OldY);
	///<summary>Set la current piece a une autre piece</summary>
	void SetPieceTo(Piece * a_TileMove);
	///<summary>Set la current piece a nullptr si elle ne l'est pas deja</summary>
	void ResetTile();
	///<summary>Change le bool m_IsEmpty a la valeur passer pour afficher les tile green pos</summary>
	void SetBoolGreen(bool a_Bool);



private:
	///<param name = "m_SurfaceOfTile">Pointeur sur la surface de la tile</param>
	SDL_Surface* m_SurfaceOfTile;
	///<param name = "m_Rect">Rectangle qui contient la sdl surface d'une tile</param>
	SDL_Rect m_Rect;
	///<param name = "m_IsEmpty">Bool si la tile est empty(pour dessiner les pos tile)</param>
	bool m_IsEmpty;
	///<param name = "IsTileEmpty">Retourne le bool si la tile est empty(pour dessiner les pos tile)</param>
	bool IsTileEmpty();
	///<param name = "m_CurrentPiece">Pointeur sur la piece dans la tile selectionner</param>
	Piece* m_CurrentPiece;
};
