#ifndef CARDPILE_H
#define CARDPILE_H

#include<iostream>
#include<stack>
#include"Card.h"
using namespace std;

void PlaceCursor(int x , int y);

class CardPile
{
protected:
	int x;
	int y;
	stack<Card*> thePile; // the collection of cards
	
public:
	CardPile(int xl, int yl);

	Card* top();
	bool isEmpty();
	Card* pop();
	void addCard(Card *aCard);
	
	// the following are sometimes overridden
	virtual bool canTake(Card *aCard);
	virtual void Print()=0;
	virtual void Next_Cards();
};

#endif