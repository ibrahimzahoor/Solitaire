#include"Solitaire.h"

Solitaire::Solitaire ()
{
		/// then ll them in
		DeckPile *Deck=new DeckPile(3, 3);
		allPiles[0] = Deck;
		
		allPiles[1] = new SuitPile(3, 35);
		allPiles[2] = new SuitPile(3, 45);
		allPiles[3] = new SuitPile(3, 55);
		allPiles[4] = new SuitPile(3, 65);

		
		allPiles[5] = new TablePile(10, 10, 1, Deck);
		allPiles[6] = new TablePile(10, 20, 2, Deck);
		allPiles[7] = new TablePile(10, 30, 3, Deck);
		allPiles[8] = new TablePile(10, 40, 4, Deck);
		allPiles[9] = new TablePile(10, 50, 5, Deck);
		allPiles[10] = new TablePile(10, 60, 6, Deck);
		allPiles[11] = new TablePile(10, 70, 7, Deck);
	
}

void Solitaire::Start_Game()
{
	int movefrom, moveto, option=0, numofcard;
	stack<Card*> card;
	stack<Card*> deck;
	bool flag= false;
	while(option != 7)
	{
		system("cls");
		cout<<*this;
		option=Menu();
		
		switch(option)
		{
		case 1:
			cout<<"Enter Pile Number to Move From:  ";
			cin>>movefrom;
			cout<<"Enter Pile to Move to:  ";
			cin>>moveto;
			cout<<"Enter Number of Cards to move:  ";
			cin>>numofcard;

			if( numofcard == 1 && allPiles[moveto + 4]->canTake( allPiles[movefrom + 4]->top() ) )
			{
				allPiles[moveto + 4]->addCard( allPiles[movefrom + 4]->top() );
				allPiles[movefrom + 4]->pop();
				if(!allPiles[movefrom + 4]->isEmpty())
				{
					allPiles[movefrom + 4]->top()->Set_faceup(true);
					break;
				}
			}
			else
			{
				
			
				for(int i=0; i<numofcard && !allPiles[movefrom + 4]->isEmpty() && allPiles[movefrom + 4]->top()->is_faceUp() ; i++)
				{
					card.push(allPiles[movefrom + 4]->pop());
					flag=true;	
				}

				if(!flag)
					break;

				if( allPiles[moveto + 4]->canTake( card.top() ) )
				{
					for(int i=0; i<numofcard; i++)
					{
						allPiles[moveto + 4]->addCard( card.top() );
						card.pop();
					}
					
					if(!allPiles[movefrom + 4]->isEmpty())
					{
						allPiles[movefrom + 4]->top()->Set_faceup(true);
						
					}
					break;
				}
				else
				{
					for(int i=0; i<numofcard; i++)
					{
						allPiles[movefrom + 4]->addCard(card.top());
						card.pop();
					}
				}
			}
			cout<<"MOVE NOT POSSIBLE"<<endl;
			break;
		
		case 2:
			cout<<"Enter Table Pile Number to Move From:  ";
		
			cin>>movefrom;
			cout<<"Enter Suit Pile to Move to:  ";
			cin>>moveto;

			if( allPiles[moveto]->canTake( allPiles[movefrom + 4]->top() ) )
			{
				allPiles[moveto]->addCard( allPiles[movefrom + 4]->top() );
				allPiles[movefrom + 4]->pop();
				if(!allPiles[movefrom + 4]->isEmpty())
				{
					allPiles[movefrom + 4]->top()->Set_faceup(true);
					break;
				}
			}
			
			cout<<"MOVE NOT POSSIBLE"<<endl;
			break;

		case 3:
			cout<<"Enter Suit Pile Number to Move From:  ";
		
			cin>>movefrom;
			cout<<"Enter Table Pile to Move to:  ";
			cin>>moveto;
			if( allPiles[moveto + 4]->canTake( allPiles[movefrom]->top() ) )
			{
				allPiles[moveto + 4]->addCard( allPiles[movefrom]->top() );
				allPiles[movefrom]->pop();
				if(!allPiles[movefrom]->isEmpty())
				{
					allPiles[movefrom]->top()->Set_faceup(true);
					break;
				}
			}
			cout<<"MOVE NOT POSSIBLE"<<endl;
			break;


		case 4:
			
			cout<<"Enter Table Pile to Move to:  ";
			cin>>moveto;
			if( allPiles[moveto + 4]->canTake( allPiles[0]->top() ) )
			{
				allPiles[moveto + 4]->addCard( allPiles[0]->top() );
				allPiles[0]->pop();
				if(!allPiles[0]->isEmpty())
				{
					allPiles[0]->top()->Set_faceup(true);
					break;
				}
			}
				cout<<"MOVE NOT POSSIBLE"<<endl;
			break;

		case 5:
			
			cout<<"Enter Suit Pile to Move to:  ";
			cin>>moveto;
			if( allPiles[moveto]->canTake( allPiles[0]->top() ) )
			{
				allPiles[moveto]->addCard( allPiles[0]->top() );
				allPiles[0]->pop();
				if(!allPiles[0]->isEmpty())
				{
					allPiles[0]->top()->Set_faceup(true);
					break;
				}
			}	
			cout<<"MOVE NOT POSSIBLE"<<endl;
			break;


		case 6:
			
			this->allPiles[0]->Next_Cards();
			break;
		};
	}
}

ostream&  operator<<(ostream& out, Solitaire& game)
{
	PlaceCursor(1, 7);
		cout<<"DECK";

	PlaceCursor(1, 47);
		cout<<"SUIT PILES";

	PlaceCursor(7, 35);
		cout<<"TABLE PILES";

	for(int i=1; i<8; ++i)
	{
		PlaceCursor(9,10*i);
		cout<<"  "<<i;
	}
	for(int i=0; i<12; i++)
		game.allPiles[i]->Print();
		
	PlaceCursor(20,3);
	return out;
}

int Solitaire::Menu()
{
	int option=0;
	cout<<"             ~*MOVE OPTIONS*~"<<endl;
	cout<<"Enter '1' To Move Card From Table Pile A to Pile B"<<endl;
	cout<<"Enter '2' To Move Card From Table Pile to Suit Pile"<<endl;
	cout<<"Enter '3' To Move Card From Suit Pile to Table Pile"<<endl;
	cout<<"Enter '4' To Move Card From Deck to Table Pile"<<endl;
	cout<<"Enter '5' To Move Card From Deck to Suit Pile"<<endl;
	cout<<"Enter '6' To Place Next Cards in Deck"<<endl;
	cout<<"Enter '7' To Quit Game"<<endl;
	cout<<">>>>>>";
	cin>>option;
	return option;
}