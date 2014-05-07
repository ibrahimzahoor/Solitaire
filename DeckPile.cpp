#include"DeckPile.h"
#include<ctime>

	DeckPile::DeckPile(int xl, int yl):CardPile(xl, yl)
	{
		for (int i = 0; i <= 3; i++)
		{
			for (int j = 1; j <= 13; j++)
			{
				Card *temp=new Card (i, j);
				addCard(temp);
			}
		}

		// then shufflee the cards
		vector<Card*> cards;
		for (int i = 0; i < 52; i++)
			cards.push_back(pop());

		srand ( unsigned ( std::time(0) ) );
		random_shuffle (cards.begin(), cards.end() );
	

		for (int i = 0; i < 52; i++)
		{
			
			this->addCard(cards[i]);
			//cards[i].flip();
			//cards[i].Print();
			//cout<<endl;
		}
	}

	void DeckPile::Next_Cards()
	{
		stack <Card *> temp;
		for(int i=0; i<3; i++)
		{
			temp.push(this->top());
			this->pop();
		}
		stack<Card*> deck;
		while(!this->isEmpty())
		{
			deck.push(this->top());
			this->pop();
		}

		for(int i=0; i<3; i++)
		{
			this->addCard(temp.top());
			temp.pop();
		}

		while(!deck.empty())
		{
			this->addCard(deck.top());
			deck.pop();
		}
	}

	void DeckPile::Print()
	{
		if(!this->isEmpty())
		{
			PlaceCursor(x, y);
			vector<Card*> cards;
			for (int i = 0; i < 3; i++)
				cards.push_back(pop());
		
			cards.at(2)->Set_faceup(true);
			cards.at(2)->Print();
			cout<<" | ";
			cards.at(1)->Set_faceup(true);
			cards.at(1)->Print();
			cout<<" | ";
			cards.at(0)->Set_faceup(true);
			cards.at(0)->Print();

			for (int i = 2; i >=0 ; i--)
			{
				this->addCard(cards[i]);
			}
		}
		//else
			//PlaceCursor(x,y);
			//cout<<"EMPTY";
	}
