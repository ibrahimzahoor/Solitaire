#include"TablePile.h"
#include"DeckPile.h"

TablePile::TablePile (int xl, int yl, int c, DeckPile *a): CardPile(xl, yl)
	 {      
		 // then initialize our pile of cards
        for (int i = 0; i < c; i++) 
        {
			addCard(a->top());
			a->pop();
		}
            // flip topmost card face up
		this->thePile.top()->flip();
    }

	bool TablePile::canTake (Card *aCard)
	{
		if (isEmpty())
			return aCard->Get_Rank() == 13;
		
		Card *topCard = top();
		return (aCard->Get_Color() != topCard->Get_Color()) && (aCard->Get_Rank() == topCard->Get_Rank() - 1);
	}

void TablePile::Print()
{
	if(isEmpty())
	{
		PlaceCursor(x,y);
		cout<<"EMPTY";
	}
	else
	{
		stack<Card*> temp;

		while( thePile.size() > 0 )
		{
			temp.push(thePile.top());
			thePile.pop();
		}

		for(int i=0; temp.size() > 0; i++)
		{
			PlaceCursor(x+i, y);

			temp.top()->Print();
			thePile.push(temp.top());
			temp.pop();
		}
	}

}