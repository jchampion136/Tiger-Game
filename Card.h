#ifndef CARD_H_
#define CARD_H_
#include <string>

class Card {

    public:
    //public enumerated initialization
    enum Color {purple, orange};

    private:
    //private member variable initialization
    int rank = 0;
    Color color{purple};
    int value = 0;

    public:
    //Public Member function initialization
    Card() {
     this->rank = rank;
     this->color = color;   
    };//Default Card constructor
    Card(int rank, Color color) {
        this->rank = rank;
        this->color = color;
    
    //value equals rank if card is purple
    if(color == purple)
        value = getRank();
    
    //Multiplies value by 2 if card is orange
    else if(color == orange)
        value = getRank()*2;

}
    std::string printCard();
    int getRank();
    Color getColor();
    std::string getColorString();
    int getValue();
};//End of Card Class
  
#endif //CARD_H_