#ifndef _CARDSHOE_H_
#define _CARDSHOE_H_

#include <card.h>

class cardshoe {
  public : 
    card* getCard();
    cardshoe(int numDecks=2);
  private :
    int cardCount[13]; // cardCounts[i] tells us how many cards are < i
    int numCards;
    void map(int cardIndex, char* name); //mapping from cardIndex to name
};


#endif //_CARDSHOE_H_
