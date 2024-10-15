//class House that contains the functions relating to the house / dealer

#include "House.h"
#include <iostream>

//flips the first hand of the house
void House::flipFirstCard() {
    if (isUp == 0)
        isUp = 1;

    else
        isUp = 0;
}

//checks if the house has busted, needs to keep hitting, or can stop
char House::houseCheck() {
    if (myHand.getTotal() > 21) {
        std::cout << "The house has busted!" << std::endl << std::endl;
        return 'n';
    }
    else if ((myHand.getTotal() > 16) && (myHand.getTotal() <= 21)) {
        std::cout << "The house will stop hitting. Let's see how the players do!" << std::endl << std::endl;
        return '-';
    } else
        return 'y';

}

//displays the house stats, accounting for if it needs to hide its first card or not
void House::houseStats(char hide ) {
    std::cout << "House" << ": ";
    if (hide == 'y') {
        std::cout << "XX     ";

        for (int i = 1; i < myHand.myCards.size(); i++)
            std::cout << myHand.myCards[i].getRank() << myHand.myCards[i].getSuit() << "     ";

        std::cout << std::endl;


    } else {

        for (auto i : myHand.myCards)
            std::cout << i.getRank() << i.getSuit() << "     ";

        int value = myHand.getTotal();
        std::cout << "(" << value << ")" << std::endl;


    }

}


