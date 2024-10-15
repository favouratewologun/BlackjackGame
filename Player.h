#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Card.h"
#include "Hand.h"
#include <string>
#include <iostream>


class Player {
    friend class Game;

private:
    Hand myHand;
    std::string playerName;

public:
    char check();
    void win(std::string winner);
    bool lose(std::string loser);
    void push(std::string pusher);
    void setName(std::string n);
    std::string getName();
    void playerStats();

};

#endif // PLAYER_H
