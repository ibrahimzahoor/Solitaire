#ifndef DECKPILE_H
#define DECKPILE_H

#include"CardPile.h"
#include<vector>
#include<algorithm>

class DeckPile: public CardPile 
{
public:
	DeckPile (int xl, int yl);
	void Next_Cards();
	void Print();
};

#endif