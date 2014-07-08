#ifndef _BASE_PLAYER_H_
#define _BASE_PLAYER_H_
/////////////////////////////////////////////////////////
// Author      : Pradeep Nalabalapu 
// Date        : July 8 2014
// Description :  Class for participants in blackjack game. 
//       There is a cardshoe that all players share
//       hit() takes a card from shoe and places in an array cards
//       A player is bust when sum of card values in his/her array > 21
/////////////////////////////////////////////////////////

#include <vector>
#include <card.h>
#include <cardshoe.h>

class baseplayer {
  public :
    void hit(); //takes card from shoe and adds to cards[]
    bool isBust();
    int getCardSum();
    baseplayer();
    void printCards(); // prints values of all cards in cards[]
    static void setShoe(cardshoe *inshoe);
    static cardshoe *getShoe() { return shoe; };
    card* getLastCard(); // gets a handle to the last card that was hit
    void resetCards(); // start fresh - clear cards[]
    int getNumCards();
  private :
    bool bust;
    static cardshoe *shoe;
    int cardSum;
  protected:
    std::vector<card*> cards; // a vector of cards to hold dealt cards
};

#endif //_BASE_PLAYER_H_
