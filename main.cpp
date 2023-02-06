#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

int main() {
  //Main Declarations
  Deck deckOfCards;
  int position = 1;
  deckOfCards.shuffle();//Shuffles deck of cards
  int random;
  int dealSize = 0;
  char playAgain = 'N';
  static vector<int>gameScoreHuman;
  static vector<int>gameScoreComputer;
  static vector<int>compWin;
  static vector<int>humanWin;
  static vector<int>roundCount;
  static int tieCount = 0;
  int humanWinCount = 0;
  int compWinCount = 0;
  static int gameCount = 0;
  gameCount++;

  //asks user to input how many rounds they want to play
  cout << "Welcome to Tiger Game!" << endl;
  cout << "How many cards should each player draw (1-10)?: ";
  cin >> dealSize;
  roundCount.push_back(dealSize);

  //Input validation that makes sure user input is within the correct parameters
  while(dealSize >= 11 || dealSize <= 0) {
    cout << "Please enter a number 1 through 10: ";
    cin >> dealSize;
  }
  
  //Initializes two instances of player and draws "dealSize" cards from the deck
  Player computer(deckOfCards,dealSize);
  Player human(deckOfCards,dealSize);

  //notifies player deck was shuffled and how many cards have been drawn
  cout << "The deck was shuffled and each player has drawn " << dealSize << " cards.\n" << endl;
  int count = dealSize; 

  //Commences Tiger Game. Loops depending on how many rounds player wants to play
  for(int i = 1; i <= dealSize; i++) {
    random = rand() % (count) + 1 ; //Initializes the random variable that will randomly pick the computers card each round
    
    //Displays Round number
    cout << "Round " << i << endl;
    cout << "-------" << endl;

    //Computer plays its card and outputs to user
    Card computerDealtCard = computer.hand.dealCard(random);
    cout << "The computer plays: " << computerDealtCard.printCard() << endl;
    cout << "Your hand: " << human.hand.printHand() << endl;//Shows user their hand
    
    /*Input validation that makes sure player picks a card thats within the vector of hand.
    If an incorrect card is picked, an error is prompted and the user is asked again.*/
    do { 
      cout << "Which card do you want to play? ";
      cin >> position;
    
      if(position > count || position < 1)
        cout << "Incorrect input. ";
    
    } while(position > count || position < 1);

    //Picks the human's chosen card and displays to user
    Card humanDealtCard = human.hand.dealCard(position);
    cout << "You played: " << humanDealtCard.printCard() << endl;
    
    //If human wins the round
    if(humanDealtCard.getValue() > computerDealtCard.getValue()) {
      cout << "You win this round!" << endl;
      human.score += humanDealtCard.getValue() + computerDealtCard.getValue();
      humanWinCount++;
    }

    //If computer wins the round
    else if(humanDealtCard.getValue() < computerDealtCard.getValue()) {
      cout << "The computer wins this round!" << endl;
      computer.score += humanDealtCard.getValue() + computerDealtCard.getValue();
      compWinCount++;
    }

    //If there's a tie
    else if(humanDealtCard.getValue() == computerDealtCard.getValue()) {
      cout << "TIE!" << endl;
      tieCount++;
    }

    //Displays current running scores to user
    cout << endl;
    cout << "Current scores: " << endl;
    cout << "--------------" << endl;
    cout << "Human: " << human.score<< endl;
    cout << "Computer: " << computer.score << endl;
    cout << endl;
    count--; //Decrements count by 1
  }

  //Fills in vector with number of wins per player
  compWin.push_back(compWinCount);
  humanWin.push_back(humanWinCount);

  //Displays final score to user at games conclusion
  cout << "FINAL SCORE: " << endl;
  cout << "Human: " << human.score<< endl;
  cout << "Computer: " << computer.score << endl;

  //Calculates final score per game
  gameScoreHuman.push_back(human.score);
  gameScoreComputer.push_back(computer.score);
  
  //If Human Wins
  if(human.score > computer.score) {
    cout << "\nHuman has won!" << endl;
  }

  //If Computer Wins
  else if(human.score < computer.score) {
    cout << "\nComputer has won!" << endl;
  }

  //If theres a tie
  else if(human.score == computer.score) {
    cout << "Game has ended in a TIE!" << endl;
  }

  do { //Asks user if they want to play TigerGame again
    cout << "Would you like to play again? (Y/N) ";
    cin >> playAgain;

  } while(playAgain != 'Y' && playAgain != 'N');
  
  if(playAgain == 'Y') { //returns main function and repeats TigerGame code again
    return main(); //Returns main
  }

  else if(playAgain == 'N') {
    for (int i = 0; i < gameCount; i++) {
      
      //outputs number of games played, number of rounds per game, Rounds won per player, and final score
      cout << "\nGame " << i+1 << endl;
      cout << "------" << endl;
      cout << roundCount.at(i) << " round(s) were played" << endl;
      cout << "Player won " << humanWin.at(i) << " round(s)" << endl;
      cout << "Computer won " << compWin.at(i) << " round(s)" << endl;
      cout << "Player scored " << gameScoreHuman.at(i) << " points" << endl;
      cout << "Computer scored " << gameScoreComputer.at(i) << " points" << endl;
    }

    return 0; //Ends program
  }
}//End of Main