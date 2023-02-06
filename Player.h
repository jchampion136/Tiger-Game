
#ifndef PLAYER_H_
#define PLAYER_H_
//#include "Hand.h"
//#include "Deck.h"

class Player {

    public:
    //public member variable Declarations
    Hand hand;
    int score{0};
    Player() = default; //default Player constructor
    Player(Deck& deck, int N){ //Initializes hand object when player instance is created
        hand = Hand(deck, N);
    }
}; //End of Player Class

#endif // PLAYErs