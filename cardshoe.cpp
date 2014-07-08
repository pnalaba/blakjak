#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctime>
#include <cardshoe.h>

cardshoe::cardshoe(int numDecks) {
  for (int i = 0; i < 13; i++) {
    cardCount[i]=4*numDecks;
  }
  numCards = 52*numDecks;
  srand(time(NULL)); //initialize seed for random generator
}

// map from cardIndex [0:12] to name of the card
void cardshoe::map(int cardIndex, char* name){
  if (name == NULL) {
    printf ("ERROR : cardshoe::map got name=NULL\n");
    exit(-1);
  }
  if ((cardIndex < 0) || (cardIndex > 12)) {
    printf ("ERROR : invalid cardIndex=%d at cardshoe::map\n",cardIndex);
    exit(-1);
  }

  if (cardIndex == 0)  strcpy(name, "A");
  else if (cardIndex == 1) strcpy(name,"J");
  else if (cardIndex == 11) strcpy(name, "K");
  else if (cardIndex == 12) strcpy(name, "Q");
  else {
    sprintf(name,"%d",cardIndex);
  }
}

card* cardshoe::getCard(){
  int index = rand()%numCards; //random number [0:numCards)
  int cardIndex;
  int cumulativeSum=0;

  for (cardIndex = 0; cardIndex < 13; cardIndex++) {
    cumulativeSum += cardCount[cardIndex];
    if (index < cumulativeSum) break;
  }
  if (cardIndex >= 13) {
    printf ("ERROR: cardIndex not found for rand index=%d sum=%d in getCard\n",
        index,cumulativeSum);
    exit(-1);
  }
  cardCount[cardIndex]--; //decrement cardCount
  numCards--;
  char name[3];
  map(cardIndex,name);
  card* newcard = new card(name); 
  return newcard;

}



