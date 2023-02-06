#include "Hand.h"
#include <string>
#include <iostream>

std::string Hand:: printHand() {//Beginning of printHand()
    //string declarations
    std::string handStr = "";

    //Outputs a list of player's hand, Number of strings determined by hand size
    for(int i = 0; i < getHandSize(); i++) {
        handStr += "[" + std::to_string(i+1);
        handStr += "] " + hand.at(i).printCard();
        handStr += " ";
    
    }

    return handStr; //Returns handStr
}//End of printHand()

Card Hand:: dealCard(int num) {//Beginning of dealCard()
    
    //Creates an instance of Card as a card in the hand
    Card cardDealt = hand.at(num-1); 
    
    //Removes previous card from hand
    hand.erase(hand.begin()+(num-1));
    
    return cardDealt; //Returns cardDealt
}//end of dealCard()

int Hand:: getHandSize(){ //beginning of getHandSize()
    return hand.size();//Returns hand size
}//End of getHandSize()