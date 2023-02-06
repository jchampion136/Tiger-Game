
#ifndef HAND_H_
#define HAND_H_
#include <string>
#include <vector>
#include "Deck.h"
#include "Card.h"

class Hand {

    private:
    //Initializes private Card Vector
    std::vector <Card> hand;

    public:
    Hand() = default; //Default Hand Constructor
    Hand(Deck& deck, int N) {
        for(int i = 0; i < N; i++) {
            Card currentCard = deck.drawCard();
            hand.push_back(currentCard);
        }
    };
    std::string printHand();
    Card dealCard(int);
    int getHandSize();
};//End of Hand Class
  
#endif //HAND_H_