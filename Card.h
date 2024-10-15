#ifndef CARD_H
#define CARD_H

#include <iostream>


enum class Suit {
    club = 1,
    diamond,
    heart,
    spade
};


enum class Rank {
    ace = 0,
    one,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    ace1,

};


class Card {
    friend class Hand;
    friend class House;
    friend class Player;
    friend class Deck;
    friend class Game;

private:
    Suit suit;
    Rank rank;
    bool isUp = 1;

public:
    bool isFaceUp();
    int getValue();
    void flip();
    void setSuit(Suit theSuit);
    void setRank(Rank theRank);
    std::string getSuit();
    std::string getRank();

};


#endif // CARD_H
