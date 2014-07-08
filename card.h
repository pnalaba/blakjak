#ifndef _CARD_H_
#define _CARD_H_
/////////////////////////////////////////////////////////
// Author      : Pradeep Nalabalapu 
// Date        : July 8 2014
// Description :  Class for playing cards. Every card has a name and a value
//       and is visible (face up) or invisible (face down)
/////////////////////////////////////////////////////////

class card {
  public :
    bool isVisible(); 
    void setVisible(bool visible);
    int getValue();
    char *getString();
    card(const char* name);
  private :
    char name[3]; 
    bool visible;
    int value;
    int calcValue();
    void setString(const char* name);
};


#endif //_CARD_H_
