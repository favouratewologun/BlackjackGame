//class Deck that has functions for creating a deck and dealing cards

#include "Deck.h"
#include "Hand.h"
#include "GenericPlayer.h"
#include <vector>
#include <time.h>
#include <iostream>
#include <alg.h>

//clears the deck of cards
void Deck::clear() {
    deckOfCards.clear();
}

//creates a new (unshuffled) deck of cards
void Deck::populate() {
    for (int i = 0; i < 4; i++) {
        Card newCard = Card();
        if (i == 0) {
            newCard.setSuit(Suit::club);

            for (int i = 0; i < 14; i++){
                newCard.setRank(static_cast<Rank>(i));
                deckOfCards.push_back(newCard);
            }


        } else if (i == 1) {
            newCard.setSuit(Suit::diamond);

            for (int i = 0; i < 14; i++){
                newCard.setRank(static_cast<Rank>(i));
                deckOfCards.push_back(newCard);
            }


        } else if (i == 2) {
            newCard.setSuit(Suit::heart);

            for (int i = 0; i < 14; i++){
                newCard.setRank(static_cast<Rank>(i));
                deckOfCards.push_back(newCard);
            }

        } else if (i == 3) {
            newCard.setSuit(Suit::spade);

            for (int i = 0; i < 14; i++) {
                newCard.setRank(static_cast<Rank>(i));
                deckOfCards.push_back(newCard);
            }

        }
    }

}

//swaps two cards in the deck
void Deck::swap(Card& card1, Card& card2) {
    Card holder = card1;

    card1 = card2;

    card2 = holder;
}

//shuffles the deck of cards
void Deck::shuffle() {

    srand(time(0));

    for (int i = 0; i < 52; i++) {
        int toSwitch = rand() % (52 - i + 1) + i;

        swap(deckOfCards[i], deckOfCards[toSwitch]);
    }

}

//deals two cards at the start
void Deck::initialDeal(Hand& hand) {
    for (int i = 0; i < 2; i++) {
        hand.myCards.push_back(deckOfCards[0]);
        deckOfCards.erase(deckOfCards.begin());
    }

    if (hand.myCards[0].getRank() == "A" && hand.myCards[1].getRank() == "A") {
        Rank newRank;
        newRank = static_cast<Rank>(14);
        hand.myCards[1].setRank(newRank);
    }

}

//indicates another card has been added
void additionalCards(GenericPlayer& gp) {
    bool moreCard = 1;
}




