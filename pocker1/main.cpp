#include "Deck.h"
#include "Hand.h"
#include "Card.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{

   Deck deck;
   int players;
   int seed;
   int sizeOfHand = 5;

   cout << "Enter seed: ";
   cin >> seed;
   srand(unsigned(seed));

   cout << "Enter number of players: ";
   cin >> players;

if(players>10){
    cout<<you need to reduce the number of player<<endl;
    return 0;
}
  // deck.Shuffle();

   Hand hands[players];



    for(int j=0;j<5;j++){
            int playercount = players;
      vector<Card> cardmain = deck.Deal(playercount);
    for(int i =0; i<players;i++){
      hands[i].add(cardmain[i]);
        }
      }

    for(int j=0;j<players;j++){
    hands[j].check();
    hands[j].showHand();
        cout<<"  "<<hands[j].valueforplayer<<endl;
    }

    for(int i=0;i<players;i++){

        hands[i].showHand();
        cout<<"  "<<hands[i].valueforplayer<<endl;

      }

    return 0;
}
