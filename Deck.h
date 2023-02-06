
#ifndef DECK_H_
#define DECK_H_
#include <vector>
#include <algorithm>
#include <iostream>
#include "Card.h"

class Deck {

    private:
    //private member vector initialization
    std::vector<Card> deck;

    public:
    //Public Member function initialization
    Deck() { //Default Deck constructor

    //Creates a deck of 20 cards
    for(int i = 0 ; i < 10; i++) { 
        for(Card::Color j = Card::purple; j <= Card::orange; j = static_cast<Card::Color>(static_cast<int>(j)+1)) {
            Card card(i+1,j);
            deck.push_back(card);
        }
    }
    }
    void shuffle();
    Card drawCard();
    int getDeckSize();
}; //End of "Deck" class

#endif //DECK_H_