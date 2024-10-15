#ifndef DECK_H
#define DECK_H

#include "Hand.h"
#include "GenericPlayer.h"
#include <vector>


class Deck {
    friend class Game;
    friend class Hand;

private:
    std::vector<Card> deckOfCards;

public:
    void populate();
    void shuffle();
    void initialDeal(Hand& hand);
    void additionalCards(GenericPlayer& gp);
    void swap(Card& card1, Card& card2);
    void clear();
};

#endif // DECK_H
