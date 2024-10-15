#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include "Player.h"
#include "House.h"


class Game {
private:
    char playAgain;
    int numberPlayers;
    std::vector<Player> allPlayers;

public:
    void playGame();
    void setPlayers();
};

#endif // GAME_H
