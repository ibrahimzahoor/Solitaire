#ifndef SUITPILE_H
#define SUITPILE_H

#include"CardPile.h"

class SuitPile: public CardPile 
{
public:
	SuitPile (int xl, int yl);
	bool canTake (Card *aCard);
	void Print();
};

#endif