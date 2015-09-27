#include "Deck.h"
#include <iostream>
#include <algorithm>

using namespace std;

 static int track = 0;
Deck::Deck()
{
  Shuffle();
}

void Deck::Shuffle()
{
   cards.erase(cards.begin(), cards.end());
   for ( int i = Card::CLUBS; i <= Card::SPADES; i++)
   {
      for ( int j = Card::TWO; j <= Card::ACE; j++ )
      {
         cards.push_back(Card(Card::SUITS(i),Card::COUNT(j)));
      }
   }
   random_shuffle (cards.begin(), cards.end());
}


/* Your code here */


  std::vector<Card> Deck::Deal(int count){

int i;
vector<Card> cards1;
    for(i=0;i<count;i++){
        cards1[i] = cards[track+i];
    }
    cards.erase(cards.begin(),cards.begin()+count);

track = track+count;
if(track>51){
cout<<"you need to reduce the numberof players"<<endl;
return;
}

return cards1;
  }


