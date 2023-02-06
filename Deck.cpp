#include "Deck.h"
#include <vector>

void Deck:: shuffle() { //Beginning of shuffle() 

    //Sets the randomization seed
    srand(unsigned(time(0))); 

    //Randomly shuffles questions
    random_shuffle(deck.begin(), deck.end());
}//End of shuffle()

Card Deck:: drawCard() { //beggining of drawCard()
    
    //creates instance of Card thats the first card of the deck vector
    Card returnCard = deck.front();

    //Removes previous card from the deck vector
    deck.erase(deck.begin());
    
    return returnCard;//Returns Card instance returnCard
}//End of drawCard()

int Deck:: getDeckSize() { //Beginning of getDeckSize
    return deck.size(); //Returns size of the Deck
}//End of getDeckSize()