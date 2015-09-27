#include "Hand.h"
#include <iostream>
#include "Card.h"
/* Your code here */

using namespace std;


void Hand::add( Card card1 ){
cards.push_back(Card(card1.getSuit(),card1.getValue()));

}

///////showHand////////////////////////////////////////////

 void Hand::showHand(){

for(int i=0;i<5;i++){
     cout<<cards[i].str();

     }}

////////  CHECK() /////////////////////////////////////
void Hand::check(){

int noofkind=0;
int value1;
int value2;

    for(int j=0;j<2;j++){
    int value1 = cards[j].getValue();
    for(int loop=j+1;loop<5;loop++){
    int value2 =cards[loop].getValue();
    if(value1 == value2){
        noofkind++;}
    }
    if(noofkind>=3){
            if(noofkind==4){
        valueforplayer = "four of a kind";
    }
    else{
        valueforplayer = "three of a kind";
    }
    return;
    }noofkind = 0;
        }noofkind = 0;
/////////////////////////////////////////////

    value1 = cards[0].getSuit();
    int noofsuit = 0;
    for(int j=1;j<5;j++){
        value2 = cards[j].getSuit();
    if(value1 == value2){
        noofsuit++;
    }
    }if(noofsuit==5){
    valueforplayer = "Flush";
    return;
    }
//////////////////////////////////////////////

    for(int j=0;j<4;j++){
    value1 = cards[j].getValue();
    for(int i=j+1;i<5;i++){
      value2 =  cards[i].getValue();
      if(value1==value2){
        noofkind++;
        value1 = value2;
        if(noofkind>=2){
                if(noofkind=2)
            valueforplayer = "Two pair";
            else if(noofkind=1)
                valueforplayer = "one pair";

        }
      }
    }
    }



}
