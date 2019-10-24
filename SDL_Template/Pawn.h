#pragma once
#include "Piece.h"


class Pawn :
	public Piece
{
public:
	Pawn(bool a_White);
	virtual ~Pawn();
	///<summary>return un si c'est le first move </summary>
	inline const bool FirstMove() { return m_FirstMove; }
	///<summary>set le first move a false ou vrai (mais surtout false :P)</summary>
	inline void SetBoolMove(bool a_Bool) { m_FirstMove = a_Bool; }

protected:
	///<param name = "m_FirstMove">bool qui dit si c'est le premier tour du pawn</param>
	bool m_FirstMove;
};

