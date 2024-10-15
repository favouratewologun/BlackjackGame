#ifndef HOUSE_H
#define HOUSE_H

#include "Hand.h"


class House {
    friend class Game;

private:
    bool isUp;
    Hand myHand;

public:
    void flipFirstCard();
    char houseCheck();
    void houseStats(char hide);
};

#endif // HOUSE_H
