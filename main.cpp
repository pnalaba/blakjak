#include <stdio.h>
#include <card.h>
#include <baseplayer.h>
#include <player.h>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

const int NumDecks=8;

//function to print the bet and all cards on the table
void printTable(baseplayer& dealer, player& player, int bet) ;

int main(int argc, char** argv) {

  cardshoe* shoe = new cardshoe(NumDecks);
  baseplayer::setShoe(shoe);

  baseplayer  dealr;
  player  playr(100);
  int bet;
  int moneyLeft;
  char temp[100];


  while ( (moneyLeft = playr.getMoneyLeft()) >0 ) { 

    do {
      printf("Enter number of chips you want to bet [1:%0d] (-1 to exit): ",
          moneyLeft);  
      cin.getline(temp,100);
      bet = atoi(temp);
      if (bet != -1 && (bet < 1  || bet > moneyLeft))
        printf("Number needs to be between 1 and %0d\n",moneyLeft);
      else
        break;
    } while(1);
    if (bet == -1) break;


    dealr.hit(); // Dealer gets one card
    playr.hit(); // player gets one card
    dealr.hit(); // dealer gets second card
    dealr.getLastCard()->setVisible(false); // card is face down
    playr.hit(); //player gets second card
    
    printTable(dealr,playr, bet);
    char next;
    // Player's hand
    do {
      printf("Enter h for hit, s for stand : ");
      cin.getline(temp, 100);
      next = temp[0];
      if (next == 'h' || next == 'H' ) {
        playr.hit();
        printTable(dealr,playr, bet);
      } else if (next == 's' || next == 'S') {
        break;
      }
    } while(!playr.isBust());
    if(playr.isBust()) {
      printf ("Player is BUST!!! card sum is %0d\n",playr.getCardSum());
      printf ("\n");
      playr.bet(bet);
    } else { // assuming we get here on stand
      dealr.getLastCard()->setVisible(true); // show dealer's 2nd card
      printTable(dealr,playr,bet);

      if(dealr.getCardSum() == 21 ) { //dealer has blackjack
        // if player also has blackjack we are even
        if (playr.getNumCards() == 2 && playr.getCardSum() == 21) {
          printf ("Draw : Dealer and player both have blackjack : Even\n");
        } else { 
          printf ("Player loses : Dealer has blackjack!! card sum is %0d\n",
              playr.getCardSum());
          playr.bet(bet);
        }
      }else if(playr.getNumCards() == 2 && playr.getCardSum() == 21) {
        printf ("Player wins : Blackjack\n");
        playr.addMoney((3*bet)/2);
      } else { 
        // Dealer's hand - hit until sum is atleast 17
        while(dealr.getCardSum() < 17) {
          dealr.hit();
          printTable(dealr,playr,bet);
          sleep(1); // sleep 1s, makes it easy to follow the play
        }
        if(dealr.getCardSum() > 21) { // dealer sum more than 21
          printf ("Player wins : Dealer is BUST!\n");
          playr.addMoney(bet);
        } else if(dealr.getCardSum() > playr.getCardSum()) {
          printf("Player loses : player card sum=%0d dealer card sum=%0d \n",
              playr.getCardSum(),dealr.getCardSum());
          playr.bet(bet);
        } else if(dealr.getCardSum() == playr.getCardSum()){
          printf ("Player draw : Dealer and player even with card sum=%0d\n",
              dealr.getCardSum());
        } else {
          printf ("Player wins: player card sum=%0d dealer card sum=%0d\n",
              playr.getCardSum(),dealr.getCardSum());
          playr.addMoney(bet);
        }
      }
    }
    printf ("=====================================================\n");
    dealr.resetCards();
    playr.resetCards();
  } 

  if(moneyLeft == 0) {
    printf ("Exiting : Player has no more credits left to play  \n");
  } else {
    printf ("=====================================================\n");
    printf ("Exiting : Player has %0d credits after the game\n", moneyLeft);
  }
  delete (shoe);
}

void printTable(baseplayer& dealer, player& player, int bet) {
  printf ("=====================================================\n");
  printf ("Bet : %0d  Remaining Chips : %0d\n",bet,player.getMoneyLeft()-bet);
  printf ("Dealer : ");
  dealer.printCards();
  printf ("\n");
  printf ("Player : ");
  player.printCards();
  printf("\n\n");
}
  

