#include <stdio.h>
#include <stdlib.h>
#include <baseplayer.h>

cardshoe* baseplayer::shoe = NULL;

baseplayer::baseplayer(){
  resetCards();
}

baseplayer::~baseplayer() {
  resetCards();
}

void baseplayer::resetCards(){
  bust = false;
  for (int i = 0; i < cards.size(); i++) {
    delete cards[i];
  }
  cards.clear();
}

void baseplayer::hit() {
  if(!shoe) {
    printf ("ERROR: shoe null in call to baseplayer::hit\n");
    exit(-1);
  }
  cards.push_back(shoe->getCard());
  //Calculate cardSum next
  cardSum = 0;
  int value;
  int numAces=0;
  //sum up all non-aces first
  for (int i=0; i < cards.size(); i++) {
    if( (value = cards[i]->getValue()) != 11) 
      cardSum += cards[i]->getValue();
    else 
      numAces++;
  }
  //sum up aces as either 11 or 1
  for (int i=0; i < cards.size(); i++) {
    if( (value = cards[i]->getValue()) == 11) {
      cardSum += cards[i]->getValue();
      numAces--;
      if ( cardSum > (21-numAces)  ) cardSum -= 10;
    }
  }
  if(cardSum > 21) bust = true;
}

bool baseplayer::isBust() {
  return bust;
}

int baseplayer::getCardSum(){
  return cardSum;
}

int baseplayer::getNumCards(){
  return cards.size();
}

void baseplayer::printCards() {
  for (int i = 0; i < cards.size(); i++) {
    if(cards[i]->isVisible()) 
      printf("%s ", cards[i]->getString());
    else
      printf("%c ",178); // trying to print a block character
  }

}

void baseplayer::setShoe(cardshoe* inshoe) {
  shoe = inshoe;
}

card* baseplayer::getLastCard() {
  if (cards.size() == 0) return NULL;
  else return ( cards[cards.size()-1]);
}


