
#include "Card.h"
#include <string>
#include <iostream>

std::string Card:: printCard() {//Beginning of printCard()
    //string variable declaration
    std::string print;

    //Prints color and rank of card
    print = getColorString();
    print+= ":";
    print+= std::to_string(getRank());
    
    return print; //Returns print string
}//End of printCard()

int Card:: getRank() { //beginning of getRank() function
    return this->rank;//Returns rank int
}//End of getRank()

Card::Color Card:: getColor() {//beginning of getColor() function
    return this->color;//Returns color enum
}//End of getColor()

std::string Card:: getColorString() { //beginning of getColorString()
    //string variable declaration
    std::string returnValue;

    //prints the kind of color of each enumerated variable used
    if(getColor() == purple) {
        returnValue = "purple";
    } 
    
    else if(getColor() == orange) {
        returnValue = "orange";
    }

    return returnValue; //Returns returnValue string
}//End of getColorString()

int Card:: getValue() { //beginning
    return this->value; //returns value int
}//End of getValue()