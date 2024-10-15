//class player that has functions for an interactive player

#include "Player.h"
#include <iostream>


//sets the player name
void Player::setName(std::string n) {
    playerName = n;
}

//gets the player's name
std::string Player::getName() {
    return playerName;
}

//announces that the player won
void Player::win(std::string winner) {
    std::cout << winner << " wins!" << std::endl;
}

//announces that the player lost
bool Player::lose(std::string loser) {
    std::cout << loser << " loses." << std::endl;
    return 1;
}

//announces that the player pushed
void Player::push(std::string pusher) {
    std::cout << pusher << " pushes." << std::endl;
}

//checks if the player has busted, can keep hitting, or can stop (at 21)
char Player::check() {
    if (myHand.getTotal() > 21) {
        lose(getName());
        return 'n';
    } else  if (myHand.getTotal() == 21) {
        std::cout << "You got 21!! Let's see how the house does..." << std::endl << std::endl;
        return '-';
    }
    else
        return 'y';
}


//displays the players cards and total value of their hand
void Player::playerStats() {
    std::cout << getName() << ": ";
    for (auto i : myHand.myCards) {
        std::cout << i.getRank() << i.getSuit() << "     ";

    }
    int value = myHand.getTotal();
    std::cout << "(" << value << ")" << std::endl;
}


