#include <stdio.h>
#include <stdlib.h>
#include <player.h>

player::player(int val){
  money=val;
}

void player::addMoney(int val) {
  money += val;
}

int player::getMoneyLeft() {
  return money;
}

void player::bet(int val) {
  if (val > money) {
    printf ("ERROR : trying to bet %d but only have money=%d\n",val,money);
    exit(-1);
  }
  money -= val;
}
