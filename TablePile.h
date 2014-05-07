#ifndef TABLEPILE_H
#define TABLEPILE_H

#include"CardPile.h"
#include"DeckPile.h"
class TablePile: public CardPile 
{
public:
	TablePile (int xl, int yl, int c, DeckPile *a);
	bool canTake (Card *aCard);
	void Print();
};

#endif