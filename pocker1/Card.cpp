#include "Card.h"
#include <sstream>

using namespace std;

Card::Card()
{
}

Card::Card( Card::SUITS _suit, Card::COUNT _val )
{
    suit = _suit;
    value = _val;
}

std::string Card::str()
{
   ostringstream os;
   os << valToStr() << suitToStr();
   return os.str();
}

string Card::valToStr(){
int cardval = getValue();

if(cardval == 2)
return "2";

if(cardval == 3)
return "3";

if(cardval == 4)
return "4";

if(cardval == 5)
return "5";

if(cardval == 6)
return "6";

if(cardval == 7)
return "7";

if(cardval == 8)
return "8";

if(cardval == 9)
return "9";

if(cardval == 10)
return "10";

if(cardval == 10)
return "J";

if(cardval == 11)
return "Q";

if(cardval == 12)
return "K";

if(cardval == 12)
return "A";


}



string Card::suitToStr(){
int cardsuit = getSuit();

if(cardsuit == 1){
    return "C";
}

if(cardsuit == 2){
    return "D";
}

if(cardsuit == 3){
    return "H";
}

if(cardsuit == 4){
    return "S";
}

}

Card::COUNT Card::getValue(){
return this->value;
}

Card::SUITS Card::getSuit(){
   return this->suit;
}

