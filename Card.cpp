//class Card that has functions for any individual card

#include "Card.h"
#include <iostream>
#include <string>
#include <vector>

//returns that the card being face up is true
bool Card::isFaceUp() {
    return 1;
}

//gets the value of each card based on its rank
int Card::getValue() {
    int cardNum = static_cast<int>(Card::rank);
    switch (cardNum) {
    case 0:
        return 11;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    case 5:
        return 5;
    case 6:
        return 6;
    case 7:
        return 7;
    case 8:
        return 8;
    case 9:
        return 9;
    case 10: case 11: case 12: case 13:
        return 10;
    case 14:
        return 1;
    default:
        return 1;

    }
}

//flips the card
void Card::flip() {
    if (isUp == 0)
        isUp = 1;
    else
        isUp = 0;


}

//sets the card suit
void Card::setSuit(Suit theSuit) {
    suit = theSuit;
}

//sets the card rank
void Card::setRank(Rank theRank) {
    rank = theRank;
}

//returns the suit of the card
std::string Card::getSuit() {
    int suitNum = static_cast<int>(Card::suit);
    switch (suitNum) {
    case 1:
        return "c";
    case 2:
        return "d";
    case 3:
        return "h";
    case 4:
        return "s";

    }
}

//returns the rank of the card
std::string Card::getRank() {
    int rankNum = static_cast<int>(Card::rank);
    switch (rankNum) {
    case 0:
        return "A";
    case 1:
        return "1";
    case 2:
        return "2";
    case 3:
        return "3";
    case 4:
        return "4";
    case 5:
        return "5";
    case 6:
        return "6";
    case 7:
        return "7";
    case 8:
        return "8";
    case 9:
        return "9";
    case 10:
        return "10";
    case 11:
        return "J";
    case 12:
        return "Q";
    case 13:
        return "K";
    case 14:
        return "A";
    default:
        return "-";

    }
}
