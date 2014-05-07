#ifndef CARD_H
#define CARD_H

class Card 
{
//internal data elds for rank and suit
private:
	bool faceup;
	int r;
	int s;

public:
	Card (int sv, int rv);

	int Get_Rank();
	int Get_Suit();
	char Get_Color();
	
	bool is_faceUp();
	void Set_faceup(bool);
	void flip();

	void Print();
};

#endif

/*
heart = 0;
spade = 1;
diamond = 2;
club = 3;
*/
