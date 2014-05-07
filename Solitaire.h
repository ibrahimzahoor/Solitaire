#ifndef SOLITAIR_H
#define SOLITAIR_H

#include"Card.h"
#include"DeckPile.h"
#include"SuitPile.h"
#include"TablePile.h"

class Solitaire
{
private:
	CardPile * allPiles[13];

public:
	Solitaire ();
	void Start_Game();
	
	int Menu();


	friend ostream&  operator<<(ostream& os, Solitaire& game);
	
};
#endif