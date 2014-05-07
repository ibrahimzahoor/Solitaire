#include"CardPile.h"
#include<Windows.h>

void PlaceCursor( int x , int y )
{
    COORD c;
    c.X = y;
    c.Y = x;

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(h,c);
}

CardPile::CardPile(int xl, int yl): x(xl), y(yl)
{}

Card * CardPile::top() 
{
	return thePile.top();
}

bool CardPile::isEmpty()
{
	return thePile.empty();
}

Card * CardPile::pop()
{
	Card * temp=thePile.top();
	thePile.pop();
	return temp;
}


// the following are sometimes overridden
void CardPile::addCard(Card *aCard)
{
	thePile.push(aCard);
}

bool CardPile::canTake(Card *aCard) 
{
	return false; 
}

void CardPile::Next_Cards()
{

}