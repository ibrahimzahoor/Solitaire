#include"Card.h"
#include<iostream>

using namespace std;
char Get_suit_char(int suit);

Card::Card(int sv, int rv): s(sv), r(rv), faceup(false)
{}

int Card::Get_Rank()
{ 
	return r; 
}

int Card::Get_Suit() 
{ 
	return s;
}

bool Card::is_faceUp() 
{ 
	return faceup; 
}

void Card::Set_faceup(bool fac)
{ 
	faceup = fac; 
}

void Card::flip()
{ 
	faceup = !faceup; 
}

char Card::Get_Color()
{
	if (is_faceUp())
		if (Get_Suit() == 0 || Get_Suit() == 2)
			return 'R';
		else
			return 'B';
	return 'Y';
}

void Card::Print()
{
	if(this->is_faceUp())
	{
		if(this->r>=2 && this->r<=10)
			cout<<this->r<<" "<<this->Get_Color()<<" "<<Get_suit_char(this->s);
		else if(this->r == 1)
			cout<<"A"<<" "<<this->Get_Color()<<" "<<Get_suit_char(this->s);
		else if(this->r == 11)
			cout<<"J"<<" "<<this->Get_Color()<<" "<<Get_suit_char(this->s);
		else if(this->r == 12)
			cout<<"Q"<<" "<<this->Get_Color()<<" "<<Get_suit_char(this->s);
		else if(this->r == 13)
			cout<<"K"<<" "<<this->Get_Color()<<" "<<Get_suit_char(this->s);
	}
	else
	{
		cout<<"*****";
	}
}

char Get_suit_char(int suit)
{
	switch(suit)
	{
	case 0:
		return 'H';
	case 1:
		return 'S';
	case 2:
		return 'D';
	case 3:
		return 'C';
	}
}