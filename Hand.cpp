//class hand containing function that deal with a hand of cards

#include "Hand.h"
#include "Card.h"
#include <string>
#include <iostream>
#include "Deck.h"

//adds a card to the hand, making sure that the ace does not cause a bust
void Hand::add(Card& card) {

    if (card.getRank() == "A") {
        int valueMinusAce = 0;
        for (auto cards : myCards) {
            if (cards.getRank() != "A")
                valueMinusAce += cards.getValue();
        }

        if (valueMinusAce > 10) {
            Rank newRank;
            newRank = static_cast<Rank>(14);
            card.setRank(newRank);
        }

    }

    myCards.push_back(card);

}

//clears the hand
void Hand::clear() { //clear cards from hand
    myCards.clear();
}

//gets the total value of the hand
int Hand::getTotal() { //return total value of hand
    int totalVal = 0;
    for (auto aCard : myCards)
        totalVal += aCard.getValue();

    return totalVal;
}

