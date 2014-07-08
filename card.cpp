#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctime>
#include <card.h>

card::card(const char* name){
  visible = true;
  setString(name);
}

bool card::isVisible() {
  return visible;
}

void card::setVisible( bool visible_) {
  visible = visible_;
}

char* card::getString() {
    return name;
}

int card::getValue() {
  return value;
}
 
int card::calcValue() {
  if (name == NULL ) {
    printf ("ERROR : name is not assigned, but card.value() called\n");
    exit(-1);
  }
  switch(name[0]) {
    case 'j': 
    case 'J':
    case 'k':
    case 'K':
    case 'q':
    case 'Q': return 10;
    case '1': if (name[1] != '0') { // if 1st char is 1, 2nd has to be 0
                printf ("ERROR : card has invalid name %s\n",name);
                exit(-1);
              }
              return 10;
    case 'a': 
    case 'A': return 11;
    default : return (name[0] - '0'); //for cards 2-9, return appropriate number
  }
}

void card::setString(const char* name_){
  if(name_ == NULL) {
    printf ("ERROR: Null pointer passed in to card.setString\n");
    exit(-1);
  }
  strcpy(name,name_);
  value = calcValue();
}



