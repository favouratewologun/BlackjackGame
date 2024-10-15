#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"


class Hand {
    friend class Deck;
    friend class Player;
    friend class House;
    friend class Game;

private:
    std::vector<Card> myCards;

public:
    void add(Card& card);
    void clear();
    int getTotal();
};

#endif // HAND_H
