#ifndef _PLAYER_H_
#define _PLAYER_H_
/////////////////////////////////////////////////////////
// Author      : Pradeep Nalabalapu 
// Date        : July 8 2014
// Description :  Class for non-dealer player in blackjack game. 
//       Adds functionality for dealing with bets and total chips
/////////////////////////////////////////////////////////

#include <baseplayer.h>

class player: public baseplayer {
  public :
    void addMoney(int val);
    int getMoneyLeft(); //returns total money of the player 
    void bet(int val); // subtracts value from total money
    player(int val=0);
  private :
    int money; // total money with the player
};


#endif //_PLAYER_H_
