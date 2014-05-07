#include"SuitPile.h"

SuitPile::SuitPile(int xl, int yl): CardPile(xl, yl)
{}

bool SuitPile::canTake (Card *aCard)
{
		if (isEmpty())
			return aCard->Get_Rank() == 1;

		Card *topCard = this->top();

		return (aCard->Get_Suit() == topCard->Get_Suit()) && (aCard->Get_Rank() == 1 + topCard->Get_Rank());
}

void SuitPile::Print()
{
	PlaceCursor(x, y);
	if(!isEmpty())
	{
		this->thePile.top()->Print();
	}
	else
	{
		cout<<"EMPTY";
	}
}
